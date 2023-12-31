/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:10:30 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:58 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print(int sig)
{
	static int	i;
	static int	c;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c <<= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig_print;

	sig_print.sa_handler = print;
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	ft_putstr_fd("PID ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
