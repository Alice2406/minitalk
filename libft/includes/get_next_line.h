/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:50:39 by aniezgod          #+#    #+#             */
/*   Updated: 2022/09/26 11:05:45 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_substr2(char *s, unsigned int start, size_t len);
int		ft_strlen2(const char *str);
char	*ft_strjoin2(char *s1, char const *s2);
int		line(char *buffer, int i);

#endif
