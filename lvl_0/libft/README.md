# lvl_0_LIBFT - Your very first own library
This library is part of the 42 Cursus - Started on Feb 2021 at 42 Lisbon.

## Index
1. [Functions](#functions)
	1. [Part One - Libc functions](#1-part-one---libc-functions)
	2. [Part Two - Additional functions](#2-part-two---additional-functions)
	3. [Part Three - Bonus part](#3-part-three---bonus-part)
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
|13 | ft_memchr       |Scans  the  initial  n bytes of the memory area pointed to by s for the first instance of c.  Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.| void *memchr(const void *s, int c, size_t n)|
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
| 1 | ft_substr       |Allocates memory and returns a substring from the string ’s’.The substring begins at index ’start’ and is of maximum size ’len’.|char *ft_substr(char const *s, unsigned int start, size_t len)|
| 2 | ft_strjoin      |Allocates memory and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|char *ft_strjoin(char const *s1, char const *s2)|
| 3 | ft_strtrim      |Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|char *ft_strtrim(char const *s1, char const *set)|
| 4 |ft_split         |Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.|char **ft_split(char const *s, char c)|
| 5 | ft_itoa         |Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.|char *ft_itoa(int n)|
| 6 | ft_strmapi      |Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.|char *ft_strmapi(char const *s, char (*f)(unsigned int, char))|
| 7 | ft_putchar_fd   |Outputs the character ’c’ to the given file descriptor|void ft_putchar_fd(char c, int fd)|
| 8 | ft_putstr_fd    |Outputs the string ’s’ to the given file descriptor.|void ft_putstr_fd(char *s, int fd)|
| 9 | ft_putendl_fd   |Outputs the string ’s’ to the given file descriptor, followed by a newline.|void ft_putendl_fd(char *s, int fd)|
| 10 | ft_putnbr_fd   |Outputs the integer ’n’ to the given file descriptor.|void ft_putnbr_fd(int n, int fd)|
### 3. Part Three - Bonus part
| # | Function | Description | Prototype |
|:-:|:---------|:------------|:----------|
| 1 | ft_lstnew       |Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.|t_list *ft_lstnew(void *content)|
| 2 | ft_lstadd_front |Adds the element ’new’ at the beginning of the list|void ft_lstadd_front(t_list **lst, t_list *new)|
| 3 | ft_lstsize      |Counts the number of elements in a list.|int ft_lstsize(t_list *lst)|
| 4 | ft_lstlast      |Returns the last element of the list.|t_list *ft_lstlast(t_list *lst)|
| 5 | ft_lstadd_back  |Adds the element ’new’ at the end of the list.|void ft_lstadd_back(t_list **lst, t_list *new)|
| 6 | ft_lstdelone    |Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed. |void ft_lstdelone(t_list *lst, void (*del)(void*))|
| 7 | ft_lstclear     |Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL.|void ft_lstclear(t_list **lst, void (*del)(void*))|
| 8 | ft_lstiter      |Iterates the list ’lst’ and applies the function ’f’ to the content of each element.|void ft_lstiter(t_list *lst, void (*f)(void *))|
| 9 | ft_lstmap       |Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.|t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))|
