Waiting to be approved by the moulinette.

everything complies with the norminette3.0 on the python version.

# lvl_1_GET_NEXT_LINE - Learning To Read
This library is part of the 42 Cursus - Started on Mar 2021 at 42 Lisbon.

## Index
1. [Thresholds](#Thresholds)
	1. [File Descriptor](#1-File-Descriptor)
	2. [The Open and Read Functions](#2-The-Open-and-Read-Functions)
		1. [Open](#Open)
		2. [Read](#Read)
	3. [Static Variables](#3-Static-Variables)
	4. [Buffer Size](#4-Buffer-Size)
	5. [Memory Management](#5-Memory-Management)
	6. [Multiple fd Reading](#6-Multiple-fd-Reading)
2. [Testing Tools](#Testing-Tools)
3. [References](#References)


## Thresholds
### 1. File Descriptor
When you want to do input or output to a file, you have a choice of two basic mechanisms for representing the connection between your program and the file: **file descriptors** and **streams**. File descriptors are represented as objects of type `int`, while streams are represented as `FILE *` objects.

File descriptors (the ones we are using) are a positive integer handle used to identify an opened file at a very low level (kernel level). These are used for functions such as `read()` or `write()`. The intigers are positive as negative values are kept for error handling.

### 2. The Open and Read Functions
These are the basic functions which will be used during the project. The `open()` will be required for the main function, so the documents pointed as an argument are accessivel, and the `read()` will go through the lines. We will go deeper into each one.

#### a. Open
The `open()` system call opens the file specified by pathname. The pathname, for this project will generally be inputed through the standard input.

The return value is a file descriptor (the fd), which corresponds to a small, positive intiger to refere to the open file.

The argument flags must include one of the following access modes: `O_RDONLY` _(Read Only)_, `O_WRONLY` _(Write Only)_, or `O_RDWR` _(Read and Write)_. There are more flags, but for our use case, O_RDONLY, or even O_RDWR will suffice.

#### b. Read
The `read()` tries to read a file up to the count of bytes the buffer has. The read operation commences at the file offset, and the file offset is incremented by the number of bytes read. If the file offset is at or past the end of file, no bytes are read, and read() returns zero.

If count is zero, `read()` may detect errors, as our program should. In the absence of any errors, or if `read()` does not check for errors, a `read()` with a count of 0 returns zero and has no other effects.

The returns values are `-1` on errror, a positive intiger showing the `<amount of bytes>` read or `0` in case the end of the document (EOD) is reached.

### 3. Static Variables
Static variables have a property of preserving their value even during calls, and therefor they are not re-initialized again. That is the main use they have and characteristic you need to understand.

There are some particular properties to the static variables
- The values store in the static variable remains in the memory while the program is running.
- The memory allocation is done in the data segment, rather than the stack. For more details I highly recommend this [article, by G4G](https://www.geeksforgeeks.org/memory-layout-of-c-program/), although it is not required for this project in particular.
- As global variables, static variables are already initialized to 0, and therefor they will not throw some random garbage.
- They need to be initialized whith constant literals. Returning values from functions won't work.

### 4. Buffer Size
"Your read must use the BUFFEZ_SIZE defined during compilation to read from a file or from stdin" && _"Your program must compile with the flag -D BUFFEZ_SIZE=xx. Which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette"_
### 5. Memory Management
### 6. Multiple fd Reading

## Testing Tools
1. [ft_atoi](https://github.com/Candec/42_cursus/blob/main/lvl_0/libft/ft_atoi.c)

## References
1. [mvaldeta - @m4r11](https://docs.google.com/document/d/12jcirTVvtEwfZAQuEBKOWjCL4Sh1_ruD3wr2wBXVrl4/edit)
2. [GNU - Streams and File Descriptors](https://www.gnu.org/software/libc/manual/html_node/Streams-and-File-Descriptors.html)
3. [SOF - Diff File Descriptor and File Pointer](https://stackoverflow.com/questions/2423628/whats-the-difference-between-a-file-descriptor-and-file-pointer)
4. [MAN - Open](https://man7.org/linux/man-pages/man2/open.2.html)
5. [MAN - Read](https://man7.org/linux/man-pages/man2/read.2.html)
6. [G4G - Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/)
