#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>


/*
	From tywong:
		Add an "extern" statement here so that your code
		can access global variables in the kernel.
*/

static int version_proc_show(struct seq_file *m, void *v)
{
	/*
		From tywong:

		using the function seq_printf():

		to call: seq_printf(m, format_string, inputs);
		example: seq_printf(m, "%s", "hello world");
	*/
	return 0;
}

static int version_proc_open(struct inode *inode, struct file *file)
{
	/*
		From tywong:

		No need to change this function.
	*/
	return single_open(file, version_proc_show, NULL);
}

static const struct file_operations version_proc_fops = {
	.open		= version_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init register_mole(void)
{
	/*
		From tywong:
			The first argument of proc_create() is the name in /proc
	*/
	proc_create("mole", 0, NULL, &version_proc_fops);
	return 0;
}

static void __exit unregister_mole(void) {
	/*
		From tywong:
			Don't change this function.
			This is the un-registration part.
	*/
	remove_proc_entry("mole", NULL);
	printk(KERN_INFO "/proc/mole removed\n");
}

module_init(register_mole);
module_exit(unregister_mole);
