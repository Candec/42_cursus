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
#### 1. Open
### 3. Static Variables
### 4. Buffer Size
### 5. Memory Management
### 6. Multiple fd Reading

## Testing Tools
1. [ft_atoi](https://github.com/Candec/42_cursus/blob/main/lvl_0/libft/ft_atoi.c)

## References
1. [GNU - Streams and File Descriptors](https://www.gnu.org/software/libc/manual/html_node/Streams-and-File-Descriptors.html)
2. [SOF - Diff File Descriptor and File Pointer](https://stackoverflow.com/questions/2423628/whats-the-difference-between-a-file-descriptor-and-file-pointer)
2. [MAN - Open](https://man7.org/linux/man-pages/man2/open.2.html)
