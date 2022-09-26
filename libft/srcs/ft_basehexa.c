/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basehexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:58:19 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/11 14:40:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, int *n)
{
	write(1, &c, 1);
	*n = *n + 1;
}

void	ft_putstr_printf(char *str, int *n)
{
	while (*str)
	{
		ft_putchar_printf(*str, n);
		str++;
	}
}

void	ft_basehexa(char formatpoint, va_list ap, int *n)
{
	unsigned int	nb;
	unsigned long	ad;

	if (formatpoint == 'x')
	{
		nb = (unsigned int)va_arg(ap, unsigned int);
		ft_putnbr_base((long)nb, "0123456789abcdef", n);
	}
	if (formatpoint == 'X')
	{
		nb = (unsigned int)va_arg(ap, unsigned int);
		ft_putnbr_base((long)nb, "0123456789ABCDEF", n);
	}
	if (formatpoint == 'p')
	{
		ad = (unsigned long)va_arg(ap, unsigned long);
		ft_putstr_printf("0x", n);
		ft_putnbr_address(ad, "0123456789abcdef", n);
	}
}

void	ft_baseten(char formatpoint, va_list ap, int *n)
{
	int			nb;
	long long	nbr;

	if (formatpoint == 'd' || formatpoint == 'i')
	{
		nb = (int)va_arg(ap, int);
		ft_putnbr_base((long)nb, "0123456789", n);
	}
	if (formatpoint == 'u')
	{
		nbr = (unsigned int)va_arg(ap, unsigned int);
		ft_putnbr_base(nbr, "0123456789", n);
	}
}

void	ft_char(char formatpoint, va_list ap, int *n)
{
	char	c;
	char	*str;

	if (formatpoint == 'c')
	{
		c = (char)va_arg(ap, int);
		ft_putchar_printf(c, n);
	}
	else if (formatpoint == 's')
	{
		str = (char *)va_arg(ap, char *);
		if (!str)
			ft_putstr_printf("(null)", n);
		else
			ft_putstr_printf(str, n);
	}
	else if (formatpoint == '%')
		ft_putchar_printf('%', n);
}
