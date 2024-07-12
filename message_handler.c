/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:48:33 by mhummel           #+#    #+#             */
/*   Updated: 2024/07/08 10:05:54 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_message(t_message *message)
{
	message->buffer_size = 1024;
	message->buffer = malloc(message->buffer_size);
	if (!message->buffer)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
}

void	expand_buffer(t_message *message)
{
	message->buffer_size *= 2;
	message->buffer = realloc(message->buffer, message->buffer_size);
	if (!message->buffer)
	{
		ft_printf("Memory reallocation failed\n");
		exit(1);
	}
}

void	reset_message(t_message *message)
{
	message->buffer[message->i] = '\0';
	ft_printf("%s\n", message->buffer);
	free(message->buffer);
	message->buffer = NULL;
	message->buffer_size = 0;
	message->buffer_index = 0;
}

void	process_char(t_message *message)
{
	if (message->buffer == NULL)
		init_message(message);
	if (message->c == '\0')
		reset_message(message);
	else
	{
		if (message->buffer_index >= message->buffer_size - 1)
			expand_buffer(message);
		message->buffer[message->buffer_index++] = message->c;
	}
}
