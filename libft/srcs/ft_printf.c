/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:33:45 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/08 17:02:24 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	va_start (ap, format);
	n = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_printf(*format, &n);
		else
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == '%')
				ft_char(*format, ap, &n);
			else if (*format == 'x' || *format == 'p' || *format == 'X')
				ft_basehexa(*format, ap, &n);
			else if (*format == 'd' || *format == 'i' || *format == 'u')
				ft_baseten(*format, ap, &n);
		}
		format++;
	}
	va_end (ap);
	return (n);
}
