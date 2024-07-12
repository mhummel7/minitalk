/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:44 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/08 10:06:07 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static t_message	message = {NULL, 0, 0, 0, 0, 0};

	if (signal == SIGUSR1)
		message.c |= (1 << message.bit_index);
	message.bit_index++;
	if (message.bit_index == 8)
	{
		process_char(&message);
		message.c = 0;
		message.bit_index = 0;
		message.i ++;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
