/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:39:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/03 00:07:01 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	size_t			index;

	if (!dest && !src)
		return (0);
	index = 0;
	destcpy = (unsigned char *) dest;
	srccpy = (unsigned char *) src;
	if (destcpy < srccpy)
	{
		while (index < size)
		{
			destcpy[index] = srccpy[index];
			index++;
		}
	}
	else
	{
		while (size--)
			destcpy[size] = srccpy[size];
	}
	return (dest);
}
