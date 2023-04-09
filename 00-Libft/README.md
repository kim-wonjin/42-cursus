# 1. Libft

|  |  |
| :-: | - |
| Topic | Libc, Makefile, relink, Header File |
| Related | Data Structures |
| Stack | C |

<br/>

# 2. Summary

Libft 프로젝트는 `Libc`를 직접 구현하는 것이다. 42Cursus의 모든 프로젝트는 각각의 필수적인 함수를 제외하고, 외부 함수를 사용하는것이 제한되어 있다. 따라서 필요한 라이브러리 함수는 직접 구현하여 사용해야 한다. 이에따라 본 프로젝트에서 구현한 라이브러리 또한 이후 여러 프로젝트에 활용된다ß.

<br/>

# 3. What I learned

표준함수들을 직접 구현하며 함수들의 동작원리에 대해 학습하였다. 또한 표준함수들의 활용과 Makefile, Header file 작성에 대해 숙달하였다. 

<br/>

# 4. Functions in Libft

## 1) Mandatory

| Name | Parameters| Return |
| - | - | - |
| ft_atoi | const char *s| int |
| ft_itoa | int n | char * |
| ft_bzero | void *s, size_t n | void |
| ft_calloc | size_t cnt, size_t n | void *|
| ft_isalnum | int c | int |
| ft_isalpha | int c | int |
| ft_isascii | int c | int |
| ft_isdigit | int c | int |
| ft_isprint | int c | int |
| ft_memccpy | void *dst, const void *src, int c, size_t n | void * |
| ft_memcpy | void *dst, const void *src, size_t n | void * |
| ft_memmove | void *dst, const void *src, size_t n | void * |
| ft_memset | void *s, int c, size_t n | void * |
| ft_memchr | const void *s, int c, size_t n | void * |
| ft_memcmp | const void *s1, const void *s2, size_t n | int |
| ft_putchar_fd | char c, int fd | void |
| ft_put_endl | char *s, int fd | void |
| ft_putnbr_fd | int n, int fd | void |
| ft_putstr_fd | char *s, int fd | void |
| ft_split | char const *s, char c | char ** |
| ft_strchr | const char *s, int c | char * |
| ft_strrchr | const char *s, int c | char * |
| ft_strdup | const char *s | char * |
| ft_strjoin | char const *s1, char const *s2 | char * |
| ft_strlcat |  char *dst, const char *src, size_t dstsize | size_t |
| ft_strlcpy | char *dst, const  char *src, size_t dstsize | size_t |
| ft_strlen | const char *s | size_t |
| ft_strmapi | char const *s, char (*f)(unsigned int, char) | char * |
| ft_strncmp | const char *s1, const char *s2, size_t n | int |
| ft_strnstr | const char *s1, const char *set, size_t n | char * |
| ft_strtrim | char const *s1, char const *set | char * |
| ft_substr | char const *s, unsigned int start, size_t len | char * |
| ft_tolower | int c | int |
| ft_toupper | int c | int |

## 2) Bonus

| Name | Parameters | Return |
| - | - | - |
| ft_lstadd_back | t_list **lst, t_list *new | void |
| ft_lstadd_front | t_list **lst, t_list *new | void |
| ft_lstclear | t_list **lst, void (*del)(void *) | void |
| ft_lstdelone | t_list *lst, void (*del)(void *) | void |
| ft_lstiter | t_list *lst, void  (*f)(void *) | void |
| ft_lstmap | t_list *lst, void *(*f)(void *), void (*del)(void *) | t_list * |
| ft_lstlast | t_list *lst| t_list * |
| ft_lstnew | void *content | t_list * |
| ft_lstsize | t_list *lst | int |

<br/>

# 5. How to compile the project

본 프로젝트의 결과물은 정적 라이브러리를 생성하는 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)와 `bonus` rule을 지원한다.
* For the Mandatory
> make all
* For the Bonus
> make bonus

<br/>

# 6. How to include the static library

외부 프로젝트에서, 본 프로젝트의 결과물인 정적 라이브러리를 활용하고자 할 때는 다음 명령어를 사용한다.

> gcc -Wall -Werror -Wextra -L <directory-name> -l <library-name>

정적 라이브러리의 이름은  `lib`로 시작해야 하며  `.a`로 끝나야 한다. 또한 <library-name>은  `lib`와  `.a`를 제외한 형태이어야 한다. 정적 라이브러리 이름을  `libft.a`로 한다면 <library-name>은  `ft`이어야 한다.
