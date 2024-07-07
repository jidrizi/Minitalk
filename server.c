/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:33:35 by jidrizi           #+#    #+#             */
/*   Updated: 2024/07/07 17:11:00 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void signal_handler(int signal) {
    if (signal == SIGUSR1) {
        printf("Received SIGUSR1\n");
    } else if (signal == SIGUSR2) {
        printf("Received SIGUSR2\n");
    }
}

int	main()
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
	{
		pause();
	}
	
	return (0);
}