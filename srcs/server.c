/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:04:45 by aniezgod          #+#    #+#             */
/*   Updated: 2022/09/26 11:20:23 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_message(int s)
{
	static int	bits = 8;
	static char	buffer[BUFF_SIZE];
	static int	i = 0;

	if (s == SIGUSR1)
		buffer[i] |= (1 << --bits);
	else if (s == SIGUSR2)
		buffer[i] &= ~(1 << --bits);
	if (bits == 0)
	{
		bits = 8;
		if (buffer[i] == '\0')
		{
			write(1, &buffer, i);
			ft_memset(buffer, 0, BUFF_SIZE);
		}
		else
			i++;
	}
}

int	main(void)
{	
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_message);
	signal(SIGUSR2, handle_message);
	while (1)
		pause();
	return (0);
}
