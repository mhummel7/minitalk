/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:41 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/30 11:25:02 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

	ft_printf("Sending message '%s' to server PID %d\n", message, server_pid);

	union sigval sv;
	sv.sival_ptr = (void *)message;
	int result = sigqueue(server_pid, SIGUSR1, sv);

	if (result == 0)
	{
		printf("Signal successfully sent to server\n");
	}
	else
	{
		perror("Error sending signal");
		return (1);
	}

	return (0);
}