/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:38:00 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:20:37 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*destcpy;
	char	*srccpy;

	if (!dest && !src)
		return (0);
	destcpy = (char *) dest;
	srccpy = (char *) src;
	while (size > 0)
	{
		size--;
		destcpy[size] = srccpy[size];
	}
	destcpy = (void *)dest;
	return (dest);
}
