# lvl_0_LIBFT - Your very first own library
This library is part of the 42 Cursus - Started on Feb 2021 at 42 Lisbon.

## Index
1. [Functions](#functions)
..1. [Part One - Libc functions](#1.-Part-One---Libc-functions)
..2. [Part Two - Additional functions](#2.-Part-Two---Additional-functions)
..3. [Part Three - Bonus part](#3.-Part-Three---Bonus-part)
2. [Cheatsheet](#cheatsheet)


## Functions
### 1. Part One - Libc functions
1. ft_atoi
2. ft_bzero
3. ft_calloc
4. ft_isalnum
5. ft_isalpha
6. ft_isascii
7. ft_isdigit
8. ft_isprint
9. ft_memset
10. ft_memcpy
11. ft_memccpy
12. ft_memmove
13. ft_memchr
14. ft_memcmp
15. ft_strchr
16. ft_strlcat
17. ft_strlcpy
18. ft_strlen
19. ft_strncmp
20. ft_strnstr
21. ft_strrchr
22. ft_strdup
23. ft_tolower
24. ft_toupper
### 2. Part Two - Additional functions
1. ft_substr
2. ft_strjoin
3. ft_strtrim
4. ft_split
5. ft_itoa
6. ft_strmapi
7. ft_putchar_fd
8. ft_putstr_fd
9. ft_putendl_fd
10. ft_putnbr_fd
### 3. Part Three - Bonus part
1. ft_lstnew
2. ft_lstadd_front
3. ft_lstsize
4. ft_lstlast
5. ft_lstadd_back
6. ft_lstdelone
7. ft_lstclear
8. ft_lstiter
9. ft_lstmap


## Cheatsheet
### 1. Part One - Libc functions

| # | Function | Description | Prototype |
|:-:|:---------|:------------|:----------|
| 1 | ft_atoi         | Converts the initial portion of the string pointed to by str to int.| int ft_atoi(const char *str)             |
| 2 | ft_bzero        | Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes  containing '\0') to that area. | void ft_bzero(void *s, size_t n)|
| 3 | ft_calloc       | Allocates size bytes and returns a pointer to the allocated memory. The memory is not initialized. |void *ft_calloc(size_t nmemb, size_t size)|
| 4 | ft_isalnum      | Checks  for an alphanumeric character                                                     | int ft_isalnum(int c)         |
| 5 | ft_isalpha      | Checks for an alphabetic character                                                        | int ft_isalpha(int c)         |
| 6 | ft_isascii      | Checks  whether  c  is a 7-bit unsigned char value that fits into the ASCII character set.|int ft_isascii(int c)          |
| 7 | ft_isdigit      | Checks for a digit (0 through 9).                                                         | int ft_isdigit(int c)         |
| 8 | ft_isprint      | Checks for any printable character including space.                                       |int ft_isprint(int c)          |
| 9 | ft_memset       | Fills the first n bytes of the memory area pointed to by s with the constant byte c.| void *ft_memset(void *s, int c, size_t n)|
|10 | ft_memcpy       | Copies n bytes from memory area src to memory area dest. The memory areas must not overlap.|void *ft_memcpy(void *dest, const void *src, size_t n)|
|11 | ft_memccpy      |Copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found.|void *memccpy(void *dest, const void *src, int c, size_t n)|
|12 | ft_memmove      |Copies  n bytes from memory area src to memory area dest.|void *memmove(void *dest, const void *src, size_t n)|
|13 | ft_memchr       |Scans  the  initial  n bytes of the memory area pointed to by s for the first instance of c.  Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.| void *memchr(const void *s, int c, size_t n);|
|14 | ft_memcmp       |Compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|int memcmp(const void *s1, const void *s2, size_t n)|
|15 | ft_strchr       |Returns a pointer to the first occurrence of the character c in the string s.|char *strchr(const char *s, int c)|
|16 | ft_strlcat      |Concatenate strings|size_t strlcat(char *dst, const char *src, size_t size)|
|17 | ft_strlcpy      |Copy strings|size_t strlcpy(char *dst, const char *src, size_t size)|
|18 | ft_strlen       |Calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').|size_t strlen(const char *s)|
|19 | ft_strncmp      |Compares the two strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.|int strcmp(const char *s1, const char *s2)|
|20 | ft_strnstr      |Locates the first occurrence of the null-terminated string needle in the string haystack, where not more than len characters are searched. Characters that appear after a ‘\0’ character are not searched.|char *ft_strnstr(const char *haystack, const char *needle, size_t len)|
|21 | ft_strrchr      |returns a pointer to the last occurrence of the character c in the string s.|char *ft_strrchr(const char *s, int c)|
|22 | ft_strdup       |returns a pointer to a new string which is a duplicate of the string s.|char *ft_strdup(char *src)|
|23 | ft_tolower      |convert uppercase letters to lowercase|int ft_tolower(int c)|
|24 | ft_toupper      |convert lowercase letters to uppercase|int ft_toupper(int c)|
### 2. Part Two - Additional functions
| # | Function | Description | Prototype |
|:-:|:---------|:------------|:----------|
| 1 | ft_substr       |||
| 2 | ft_strjoin      |||
| 3 | ft_strtrim      |||
| 4 |ft_split         |||
| 5 | ft_itoa         |||
| 6 | ft_strmapi      |||
| 7 | ft_putchar_fd   |||
| 8 | ft_putstr_fd    |||
| 9 | ft_putendl_fd   |||
| 10 | ft_putnbr_fd   |||
### 3. Part Three - Bonus part
| # | Function | Description | Prototype |
|:-:|:---------|:------------|:----------|
| 1 | ft_lstnew       |||
| 2 | ft_lstadd_front |||
| 3 | ft_lstsize      |||
| 4 | ft_lstlast      |||
| 5 | ft_lstadd_back  |||
| 6 | ft_lstdelone    |||
| 7 | ft_lstclear     |||
| 8 | ft_lstiter      |||
| 9 | ft_lstmap       |||
