/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:01:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/16 10:35:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 128

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

char					***ft_tabsplit_paragraph(char **s);
void					ft_putstrstr(char **s);
int						ft_strstrlen(char **s);
char					*ft_strstrjoin(int nb, ...);
char					**ft_strstrdup(char **s);
char					**ft_strstrnew(size_t size);
void					ft_strstrdel(char **s);
int						get_next_line(int fd, char **line);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_atoi(const char *str);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
char					*ft_strdup(const char *s1);
char					*ft_strncpy(char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_itoa(int n);
char					*ft_strnew(size_t size);
char					*ft_strmap(char const *s, \
							char (*f)(char));
char					*ft_strmapi(char const *s, \
							char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, \
							unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putnbr(int n);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void					*ft_memmove(void *s1, const void *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstprint(t_list **alst);
void					ft_lstdel_all(t_list *alst);
void					ft_lstadd_end(t_list **alst, t_list *new);

#endif
