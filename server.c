/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:33:35 by jidrizi           #+#    #+#             */
/*   Updated: 2024/07/10 18:38:02 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	message_reciever(int signal)
{
	static int		bits = 0;
	static int		x = 0;
	unsigned char	character;

	bits <<= 1;
	if (signal == SIGUSR1)
		bits |= 1;
	x++;
	if (x == 8)
	{
		character = bits;
		write(1, &character, 1);
		bits = 0;
		x = 0;
	}
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./server\n");
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, message_reciever);
	signal(SIGUSR2, message_reciever);
	while (1)
		pause();
	return (0);
}
