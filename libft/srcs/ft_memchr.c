/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:35:36 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:32:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
		{
			return ((void *)d + i);
		}
		i++;
	}
	return (NULL);
}	
