/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:04:56 by aniezgod          #+#    #+#             */
/*   Updated: 2023/01/21 13:53:51 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_data {
	int	received_bit;
}				t_data;

//---------------------------------SERVER------------------------------------//

void					get_message(int sig, siginfo_t *info, void *context);
static unsigned char	*stock_message(unsigned char *str, unsigned char c);

//---------------------------------CLIENT------------------------------------//

void					send_str(int pid, char *str);
void					send_char(int pid, char c);
void					receive_bit_message(int sig);

#endif