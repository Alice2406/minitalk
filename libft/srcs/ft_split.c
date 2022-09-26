/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:43:48 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:56:04 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count_words;
	int	f;

	f = 1;
	i = 0;
	count_words = 0;
	if (str[0] == '\0')
		return (count_words);
	while (str[i])
	{
		if (str[i] == c)
			f = 1;
		if (f == 1 && str[i] != c)
		{
			f = 0;
			count_words++;
		}
		i++;
	}
	return (count_words);
}

static int	len_mot(const char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
			return (len);
		i++;
		len++;
	}
	return (len);
}

static char	**ft_split2(char **chaine, int j, const char *str, const char c)
{
	int	i;
	int	r;
	int	len_mot_chaine;

	i = 0;
	while (j < count_words(str, c))
	{
		len_mot_chaine = len_mot(str, c, i);
		chaine[j] = malloc(sizeof(char) * len_mot_chaine + 1);
		if (chaine[j] == NULL)
			return (NULL);
		while (str[i] == c)
			i++;
		r = 0;
		while (r < len_mot_chaine)
		{
			chaine[j][r] = str[i];
			r++;
			i++;
		}
		chaine[j][r] = '\0';
		j++;
	}
	chaine[j] = 0;
	return (chaine);
}

char	**ft_split(char const *s, char c)
{
	char	**chaine;
	int		j;

	if (!s)
		return (0);
	j = 0;
	if (count_words(s, c) != 0 || *s)
	{
		chaine = malloc(sizeof(char *) * (count_words(s, c) + 1));
		if (!chaine)
			return (NULL);
		chaine = ft_split2(chaine, j, s, c);
		return (chaine);
	}
	else
	{
		chaine = malloc(sizeof(char *) * 1);
		if (!chaine)
			return (NULL);
		chaine[0] = 0;
		return (chaine);
	}
}
