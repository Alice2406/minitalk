/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:36:06 by aniezgod          #+#    #+#             */
/*   Updated: 2022/01/02 23:33:01 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t			n;
	unsigned char	*cpyp1;
	unsigned char	*cpyp2;

	cpyp1 = (unsigned char *)p1;
	cpyp2 = (unsigned char *)p2;
	n = 0;
	while (n < size)
	{
		if (cpyp1[n] == cpyp2[n])
			n++;
		else
			return (cpyp1[n] - cpyp2[n]);
	}
	return (0);
}
