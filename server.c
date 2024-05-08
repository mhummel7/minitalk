/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:44 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/08 09:02:07 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int message)
{
	static char	c;
	static int	i;

	if (message == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		c = 0;
		i = 0;
	}
}



int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
