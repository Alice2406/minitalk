/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:47:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/11 13:20:04 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_address(unsigned long nbr, char *base, int *n)
{
	unsigned int	size;

	size = ft_strlen_printf(base);
	if (nbr >= size)
	{
		ft_putnbr_address(nbr / size, base, n);
		ft_putnbr_address(nbr % size, base, n);
	}
	else
		ft_putchar_printf(base[nbr], n);
}

int	ft_strlen_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long nbr, char *base, int *n)
{
	int	size;

	size = ft_strlen_printf(base);
	if (nbr < 0)
	{
		ft_putchar_printf('-', n);
		nbr *= (-1);
	}
	if (nbr >= size)
	{
		ft_putnbr_base(nbr / size, base, n);
		ft_putnbr_base(nbr % size, base, n);
	}
	else
		ft_putchar_printf(base[nbr], n);
}
