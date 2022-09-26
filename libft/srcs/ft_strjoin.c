/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:53:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/09 15:20:19 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chaine;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	chaine = (char *)malloc(sizeof(*s1) * (i + j + 1));
	if (!chaine)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
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
	return (chaine);
}
