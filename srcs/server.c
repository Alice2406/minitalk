/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:04:45 by aniezgod          #+#    #+#             */
/*   Updated: 2023/01/21 14:03:50 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	*stock_message(unsigned char *str, unsigned char c)
{
	unsigned char	*tmp;
	int				i;
	static int		len = 1;

	tmp = NULL;
	i = 0;
	tmp = malloc(++len);
	if (!tmp)
		return (NULL);
	while (len > 2 && str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	if (len > 2)
		free(str);
	if (c == '\0')
		len = 1;
	return (tmp);
}

void	print_str(unsigned char *str, int client_pid)
{
	ft_printf("%s\n", str);
	free(str);
	kill(client_pid, SIGUSR1);
}

void	get_message(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;
	static unsigned char	*str;

	(void)context;
	if (sig == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		str = stock_message(str, c);
		if (c == 0)
			print_str(str, info->si_pid);
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
