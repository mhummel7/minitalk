/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:08:22 by mhummel           #+#    #+#             */
/*   Updated: 2024/05/07 12:15:02 by mhummel          ###   ########.fr       */
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

void	handler(int signum);
void	send_message(int server_pid, char *message);

#endif