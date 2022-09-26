/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:03:44 by aniezgod          #+#    #+#             */
/*   Updated: 2022/09/26 11:20:45 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit != 0)
	{
		if (c & (1 << (--bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char(pid, str[i]);
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
		send_str(ft_atoi(av[1]), av[2]);
	else
	{
		ft_printf("Error : nb of arguments\n");
		return (0);
	}
}
