/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:44 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/30 11:25:37 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_received_message[1000];

void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	size_t	message_length;

	(void)sig;
	(void)context;
	ft_printf("Received SIGUSR1\n");
	if (info->si_value.sival_ptr == NULL)
	{
		ft_printf("Error: Received message pointer is NULL\n");
		return ;
	}
	message_length = strlen((char *)info->si_value.sival_ptr);
	if (message_length >= sizeof(g_received_message))
	{
		ft_printf("Error: Received message is too large\n");
		return ;
	}
	strcpy(g_received_message, (char *)info->si_value.sival_ptr);
	ft_printf("Server received message: %s\n", g_received_message);
}

void	sigusr2_handler(int sig)
{
	ft_printf("Received SIGUSR2\n");
	(void)sig;
}

int	main(void)
{
	struct sigaction sa1, sa2;

	ft_printf("Server PID: %d\n", getpid());

	memset(&sa1, 0, sizeof(sa1));
	sa1.sa_sigaction = sigusr1_handler;
	sa1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);

	sa2.sa_handler = sigusr2_handler;
	sigemptyset(&sa2.sa_mask);
	sigaction(SIGUSR2, &sa2, NULL);

	while (1)
		sleep(1);

	return (0);
}