/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:33:32 by jidrizi           #+#    #+#             */
/*   Updated: 2024/07/12 18:10:22 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	send_msg_char(pid_t pid, char c)
{
	int	index;

	index = 7;
	while (index >= 0)
	{
		if ((c >> index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(60);
		index--;
	}
}

static	void	send_message(pid_t pid, char *msg)
{
	while (*msg)
	{
		send_msg_char(pid, *msg);
		msg++;
	}
	send_msg_char(pid, '\0');
}


int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
		return (ft_printf("Usage: ./client [PID] [msg]\n"), EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_message(pid, msg);
	return (0);
}
