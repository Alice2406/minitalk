/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:30:53 by aniezgod          #+#    #+#             */
/*   Updated: 2022/03/11 14:39:22 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_basehexa(char formatpoint, va_list ap, int *n);
void	ft_baseten(char formatpoint, va_list ap, int *n);
void	ft_char(char formatpoint, va_list ap, int *n);
void	ft_putchar_printf(char c, int *n);
void	ft_putstr_printf(char *str, int *n);
int		ft_strlen_printf(char *str);
int		ft_printf(const char *format, ...);
void	ft_putnbr_base(long nbr, char *base, int *n);
void	ft_putnbr_address(unsigned long nbr, char *base, int *n);

#endif
