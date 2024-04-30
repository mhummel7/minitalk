/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:08:22 by mhummel           #+#    #+#             */
/*   Updated: 2024/04/30 11:26:40 by mhummel          ###   ########.fr       */
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

char	g_received_message[1000];
void	sigusr1_handler(int sig, siginfo_t *info, void *context);
void	sigusr2_handler(int sig);

#endif