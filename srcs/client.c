/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:03:44 by aniezgod          #+#    #+#             */
/*   Updated: 2023/01/21 12:38:15 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	receive_bit_message(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("message received\n");
		exit (0);
	}
	else if (sig == SIGUSR2)
		g_data.received_bit = 1;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 128;
	while (bit >= 1)
	{
		if (c & bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit /= 2;
		sleep(1);
		while (!g_data.received_bit)
			pause();
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
	g_data.received_bit = 0;
	signal(SIGUSR1, receive_bit_message);
	signal(SIGUSR2, receive_bit_message);
	if (ac == 3 && !(ft_atoi(av[1]) <= 0))
		send_str(ft_atoi(av[1]), av[2]);
	else
		ft_printf("Error : nb of arguments\n");
	return (0);
}
