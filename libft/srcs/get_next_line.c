/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:00:02 by aniezgod          #+#    #+#             */
/*   Updated: 2022/09/26 11:05:35 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen2(s1);
	j = ft_strlen2(s2);
	chaine = (char *)malloc(sizeof(*s1) * (i + j + 1));
	if (!chaine)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		chaine[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		chaine[j + i] = s2[j];
		j++;
	}
	chaine[j + i] = '\0';
	return (free(s1), chaine);
}

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len < (size_t)ft_strlen2(s))
		chaine = (char *)malloc(sizeof(*s) * (len + 1));
	else
		chaine = (char *)malloc(sizeof(*s) * (ft_strlen2(s) + 1));
	if (!chaine)
		return (0);
	while (i != start && s[i])
		i++;
	while (s[i] && j < len)
		chaine[j++] = s[i++];
	if (i >= start - 1)
		free(s);
	if (j == 0)
		return (free(chaine), NULL);
	chaine[j] = '\0';
	return (chaine);
}

int	line(char *buffer, int i)
{
	if (!buffer)
		return (-1);
	while (1)
	{
		if (buffer[i] == '\n' || buffer[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			i;
	static char	*chaine;
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while ((i > 0) && (line(chaine, 0) == -1
			|| ft_strlen2(chaine) - line(chaine, 0) == 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		chaine = ft_strjoin2(chaine, buffer);
	}
	line_read = ft_substr2(chaine, 0, (line(chaine, 0) + 1));
	i = line(chaine, 0) + 1;
	chaine = ft_substr2(chaine, i, (ft_strlen2(chaine) - i));
	return (free(buffer), line_read);
}
