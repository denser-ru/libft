/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <cayako@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:26:52 by cayako            #+#    #+#             */
/*   Updated: 2021/11/09 13:56:47 by denser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_2list
{
	void			*content;
	size_t			content_size;
	struct s_2list	*prev;
	struct s_2list	*next;
}					t_2list;

/*
** FT_GET..
*/
int					ft_getch(void);
int					ft_getint(void);

/*
** FT_MEM..
*/
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** FT_OTHERS
*/
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_n(const char *str, size_t n);
char				*ft_itoa(int n);
int					ft_itoa_mem_d(void *dest, unsigned int nb);
void				ft_pass_whitespace(char **s);
long long			ft_abs(long long n);
long double			ft_abs_ld(long double n);

/*
** FT_IS..
*/
int					ft_isdigit(int c);
int					ft_iswhitespace(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** FT_LST..
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstcut(t_list **root, t_list *cut,
						void (*del)(void *, size_t));
void				ft_lstdelcontent(void *content, size_t size);
t_list				*ft_lstpushf(t_list **root, void *content,
						size_t content_size);
t_list				*ft_lstpushb(t_list **root, void *content,
						size_t content_size);
t_list				*ft_lststrsplit(char const *s, char c);
char				**ft_lststrtoarr(t_list *lststr);
int					ft_lstsize(t_list *list);
void				ft_lstputstr(t_list *lst);
void				ft_lstputendl(t_list *lst);
void				ft_lstputstr_fd(t_list *lst, int fd);
void				ft_lstputendl_fd(t_list *lst, int fd);

/*
** FT_2LST..
*/
void				ft_2lstcut(t_2list **root, t_2list *cut,
						void (*del)(void *, size_t));
t_2list				*ft_2lstnew(void const *content, size_t content_size);
void				ft_2lstinsert(t_2list **prev, t_2list *new);
void				ft_2lstdel(t_2list **alst, void (*del)(void *, size_t));
void				ft_2lstdelone(t_2list **alst, void (*del)(void *, size_t));
t_2list				*ft_2lstpushf(t_2list **root, void *content,
						size_t content_size);
t_2list				*ft_2lstpushb(t_2list **root, void *content,
						size_t content_size);

/*
**  FT_PUT..
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr(char const *s, size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnendl(char const *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr2d(char **s);
void				ft_putendl2d(char **s);
int					ft_putchar_mem(t_putmem *out, char const c);
int					ft_putstr_mem(t_putmem *out, char const *s);
int					ft_putnbr_to_mem(char *out, int n);
int					ft_putnstr_mem(t_putmem *out, char const *s, size_t n);
int					ft_putnbr_mem(t_putmem *out, int n);
void				ft_putnstr_fd(char const *s, size_t n, int fd);
void				ft_putnendl_fd(char const *s, size_t n, int fd);

/*
** FT_STR..
*/
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

#endif
