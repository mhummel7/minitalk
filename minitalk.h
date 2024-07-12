/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:08:22 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/08 10:05:31 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_message {
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_index;
	int		bit_index;
	char	c;
	int		i;
}			t_message;

void	handler(int signum);
void	send_message(int server_pid, char *message);
void	process_char(t_message *message);
void	init_message(t_message *message);
void	expand_buffer(t_message *message);
void	reset_message(t_message *message);

#endif