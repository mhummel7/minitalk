/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:41 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/08 09:24:02 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int server_pid, char *message)
{
	int		i;
	int		j;

	i = 0;

	while (message[i])
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			message[i] >>= 1;
			usleep(150);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int server_pid;
	char *message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server_pid, message);
	ft_printf("Message sent\n");
	return (0);
}