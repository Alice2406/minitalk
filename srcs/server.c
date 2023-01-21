/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:04:45 by aniezgod          #+#    #+#             */
/*   Updated: 2023/01/21 12:34:18 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stock_message(char c, int client_pid)
{
	static char	*str = NULL;
	char		*dst;
	int			i;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!dst)
		return ;
	if (str)
	{
		i = -1;
		while (str[++i])
			dst[i] = str[i];
		free(str);
	}
	dst[i] = c;
	dst[++i] = 0;
	str = ft_strdup(dst);
	free(dst);
	if (!c)
	{
		ft_printf("%s\n", str);
		str = NULL;
		kill(client_pid, SIGUSR1);
	}
}

void	get_message(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;

	(void)context;
	if (sig == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		stock_message(c, info->si_pid);
		c = 0;
		bit = 128;
	}
	else
		bit /= 2;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = get_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
