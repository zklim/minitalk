/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:03:21 by zhlim             #+#    #+#             */
/*   Updated: 2023/06/30 17:28:42 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	signal_handler(int sig)
{
	static int	bit;
	static char	c;

	if (sig == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = '\0';
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("PID number: %d\n", pid);
		ft_printf("Pending message to print...\n");
		while (1)
		{
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
			pause();
		}
	}
	else
	{
		ft_printf("No arguments allowed\n");
		ft_printf("Stopping process\n");
		return (0);
	}
}
