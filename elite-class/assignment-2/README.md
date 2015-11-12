# ESTR 3102 Assignment 2 - Encrypted open()

In this assignment, you will copy the `open()` system call and implement a new system call called `eopen()`, or the **encrypted open()**.

## Specification

The specification can be found in this repo: [ESTR3102-assign2.pdf](ESTR3102-assign2.pdf). Note that this is an individual assignment.

## Encryption and Password

One of the eye-catching point of this assignment is **encryption**. However, you are not required to use the cutting\--edge encryption technologies, such as AES.

Rather, you will be implement:

- **XOR** as the encryption function;
- Byte-by-byte encryption / decryption;
- Encryption / decryption based on the encryption key supplied by the user of the `eopen()` system call.

## Example

```
File   Content: HELLO WORLD
Encryption Key: TYWONG
```

The encryption is done by the XOR operation. Say, for the first character:
```
Encryption: H (72) ^ T (84) = 28
```
So, by applying encryption key repeatedly, we will have the following result:

```
Input in char  : H   E   L   L   O       W   O   R   L   D
Input in ASCII : 72  69  76  76  79  32  87  79  82  76  68
Encrypted Input: 28  28  27  3   1   103 3   22  5   3   10
```
By applying the XOR encryption with the same encryption key over the encrypted input, we will get the plaintext again.

## Deadline and Demonstration

The deadline of this assignment is **16:30, 2015 Nov 28 (Friday)**. We will have demonstrations for every student:

1. Our tutor and lecturer will demonstrate your program one-by-one.
2. It would not take more than 10 minutes per demonstration.
3. There is no need for you to present your work.

**Good luck**.
