/*
	Modified from: http://wiki.tldp.org/lkmpg/en/content/ch05/2_6
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

#define FILE_NAME "buffer_test" // module name as it appears under /proc

#define MAX_SIZE 2048           // buffer size

static struct semaphore sem;
static char buf[MAX_SIZE];          // buffer
static unsigned long size = 0;      // size of the data held in the buffer
static struct proc_dir_entry *proc;

static ssize_t proc_read(struct file *fp, char *buffer, size_t len, loff_t *offset) {
  static int finished = 0;
  if(finished) {
    printk(KERN_INFO "proc read finished. Read: %s\n", buffer);
    finished = 0;
    return 0;
  }
  finished = 1;
  if(copy_to_user(buffer, buf, size)) {
    return -EFAULT;
  }
  printk(KERN_INFO "read %lu bytes\n", size);
  return size;
}

static ssize_t proc_write(struct file *fp, const char *userBuf, size_t len, loff_t *off) {
  if(len > MAX_SIZE) {
    printk(KERN_INFO "buffer length greater than MAX_SIZE\n");
    size = MAX_SIZE;
  } else {
    size = len;
  }

  if(copy_from_user(buf, userBuf, size)) {
    return -EFAULT;
  }

  printk(KERN_INFO "Wrote %lu bytes from /proc/%s\n", size, FILE_NAME);
  return size;
}

int proc_open(struct inode *inode, struct file *fp) {
  try_module_get(THIS_MODULE);
  return 0;
}

int proc_close(struct inode *inode, struct file *fp) {
  module_put(THIS_MODULE);
  return 0;
}

static struct file_operations fops = {
  read: proc_read,
  write: proc_write,
  open: proc_open,
  release: proc_close,
};

int init_module(void) {
  if(!(proc = proc_create(FILE_NAME, 0, NULL, &fops)))
    return -ENOMEM;
  return 0;
}

void cleanup_module(void) {
  remove_proc_entry(FILE_NAME, NULL);
}
