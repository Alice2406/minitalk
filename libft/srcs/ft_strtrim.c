/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:01:30 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:53:47 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	size_str(char const *s1, char const *set)
{
	int	size;

	size = ft_strlen(s1) - 1;
	while (size)
	{
		if (is_charset(s1[size], set) == 1)
			size--;
		else
			return (size + 1);
	}
	return (0);
}

static unsigned int	find_start(char const *s1, char const *set)
{
	unsigned int	start;
	int				i;

	start = 0;
	i = 0;
	while (s1[i])
	{
		if (is_charset(s1[i], set) == 1)
		{
			start++;
			i++;
		}
		else
			return (start);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	int				size;
	unsigned int	start;

	if (!s1 || !set)
		return (NULL);
	size = size_str(s1, set);
	start = find_start(s1, set);
	str = ft_substr(s1, start, size - start);
	return (str);
}
