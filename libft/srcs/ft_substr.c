/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:08:46 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:45:00 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len < (size_t)ft_strlen(s))
		chaine = (char *)malloc(sizeof(*s) * (len + 1));
	else
		chaine = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!chaine)
		return (0);
	while (i != start && s[i])
		i++;
	while (s[i] && j < len)
	{
		chaine[j] = s[i];
		j++;
		i++;
	}
	chaine[j] = '\0';
	return (chaine);
}
