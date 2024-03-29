/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:12:05 by aniezgod          #+#    #+#             */
/*   Updated: 2023/01/21 12:38:52 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
char			*ft_strrchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memset(void *b, int c, size_t len);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_memcmp(const void *p1, const void *p2, size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
long			ft_atol(const char *str);
int				ft_str_is_digit(char *str);

#endif
