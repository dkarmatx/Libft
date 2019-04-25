/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:02:57 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/25 23:39:18 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define MAX_LL 9223372036854775807
# define MAX_INT 2147483647
# define MAX_ULL 18446744073709551615

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
** :: MEMORY FUNCTIONS                                          **
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
*/

/*
** Free memory from (*ap), and set (*ap) = 0.
*/
void				ft_memdel(void **ap);
/*
** Returns a pointer to a fresh, 0 set memory.
*/
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** CHECK THE MAN.
*/
void				*ft_realloc(void *old, size_t size);
/*
** Prints (size) bytes in std-output with hex.
*/
void				ft_hexdump(void *ptr, size_t size);
/*
** Duplicates (len) bytes and allocates them in new memory.
** If allocation failed returns 0, otherwise returns pointer
** to a new memory.
*/
void				*ft_memdup(void *start, size_t len);

/*
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
** :: STRING EDIT FUNCTIONS                                     **
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
*/

/*
** Returns a pointer to a fresh, 0 set string.
*/
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_lltoa_base(long long nb, int base);
char				*ft_itoa(int n);
long long			ft_atoll_base(const char *str, int base);
int					ft_atoi_base(const char *str, int base);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

/*
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
** :: OUTPUT FUNCTIONS                                          **
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putll_base_fd(long long nb, int fd, int base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);

/*
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
** :: OTHERS AND OTHERS                                         **
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
*/

/*
** Returns amount of words in a string (s), delimited
** by chrarecter (c).
*/
unsigned int		ft_countw_delim(char const *s, char c);
void				ft_print_bytes(void *ptr, int size);

/*
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
** :: LIST EDIT FUNCTIONS                                       **
** :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: **
*/

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are initialized by copy
** of the parameters of the function. If the parameter content is nul, the
** variable content is initialized to NULL and the variable content_size is
** initialized to 0 even if the parameter content_size isn’t.
** The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
** Takes as a parameter a link’s pointer address and frees the
** memory of the link’s content using the function del given as
** a parameter, then frees the link’s memory using free(3). The
** memory of next must not be freed under any circumstance.
** Finally, the pointer to the link that was just freed must be
** set to NULL (quite similar to the function memdel in the
** mandatory part).
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter the adress of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to
** the link that was just freed must be set to NULL (quite similar
** to the function memdel from the mandatory part).
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
** Adds the element new at the beginning of the list.
*/
void				ft_lstadd(t_list **alst, t_list *new_lst);
/*
** Iterates the list lst and applies the function f to each link.
*/
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** Iterates a list lst and applies the function f to each link.
** The first "non-zero" call of function f for link, will return
** that link.
*/

#endif
