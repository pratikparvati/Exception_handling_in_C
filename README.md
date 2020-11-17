# Exception handling in C using setjmp and longjmp
An exception is an uncommon situation; regularly a run-time error, which the body of code has not been designed to handle.

Exception handling is a method that allows the manipulate of execution to be transferred to an alternative block of code when an exception has been detected. Systems are invariably subject to stresses that are outside the bounds of normal operation such as those caused by

- attack
- erroneous or malicious inputs
- hardware or software faults
- unanticipated user behavior
- unexpected environmental changes

These systems must continue to deliver essential services in a timely manner, safely and securely.

## Why are Exceptions Needed?

- The types of problems which cause exceptions (running out of resources, bad disk drive etc) are found at a low level (say in a device driver)

- The low-level code implementer does not know what your application wants to do when the problem occurs, so he/she “throws” the problem “up” to you

## Error Detection & Recovery

Error handling is often separated into detection and recovery:

- **Detection**: discovering that an error has occurred.
- **Recovery**: determining how to handle the error.

## setjmp and longjmp

The function `setjmp()` is a way of recording information about where a program is in its execution so that you can later jump back to that point. You give it a variable of type `jmp_buf`, in which it will store that information. `setjmp()` returns 0 the first time it returns.

Later on, you can use the function `longjmp(jmp_buf, value)` to immediately begin execution back at the point where you called `setjmp()`. To your program, it will look like `setjmp()` returned a second time. The value argument you pass to `longjmp()` will be returned this time, to help differentiate the second return.

So, when the `setjmp(jmpbuf)` function is called
- saves its return address and stack pointer into a `jmpbuf` structure 
- Returns zero.
- A `jumpbuf` is only valid until the routine that called `setjmp` returns.

A call to `longjmp(jmpbuf, retval)` results in `setjmp` returning, now with the (presumably non-zero) value `retval`. This is implemented by effectively
- Reconstructing `setjmp`'s stack frame (including SP and PC).
- Returning from `setjmp` again (to its original caller), with `retval` in the register used to return values.

Here’s an example to help illustrate:

```C++
#include <stdio.h>
#include <setjmp.h>


jmp_buf env;
int main(int argc, char **argv)
{
    if (setjmp(env) == 0) {
        printf("jump buffer is set successfully!\n");
    } else {
        printf("We jumped!\n");
        return 0;
    }

    printf("Getting ready to jump!\n");
    longjmp(env, 1);
    printf("This will never execute...\n");
    return 0;
}
```
If you compile and run this program, you will get the following output:

```
jump buffer is set successfully!
Getting ready to jump!
We jumped!
```
## Exception handling

A cool feature about `setjmp()` and `longjmp()` is that they can be used to make your own exception handling in C. If you have used any higher-level, OOP languages before; you may be familiar with the notion of an exception handler, using the try/catch/throw keywords.

```
try {
    // May not work code goes here
}
catch(SomeExceptionType e) {
    // Deal with error here
}
```
C does not have native exception support; but you can make your own with some clever use of `setjmp()`, `longjmp()` and preprocessor macros.

`main.c` in this repository is used to demonstrate the control flow using the defined macros.

To compile and run 
```
$ gcc main.c -o main
$ ./main
```

### Macros

- **TRY** →	 This macro creates the variable `Buf`, used for storing the state of the stack.
- **CATCH** → Used for handling the exception
- **END_TRY** →	 Code inside CATCH and END_TRY contains code for exception handling
- **THROW** → Used to throw exception for handling when occurs

`test.c` sample demostration of `Divide by Zero` exception handling.

To compile and run 
```
$ gcc test.c -o test
$ ./test
```

