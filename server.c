/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:10:30 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/13 18:43:45 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print(int sig)
{
	static int	i = 0;
	static int	c = 0;
	
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c <<= 1;
	i++;
	ft_printf("->%i\n", c);
	if (i == 7)
	{
		ft_printf("=%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sig_print;
	
	sig_print.sa_handler = print;
	sigemptyset(&sig_print.sa_mask);
	sigaddset(&sig_print.sa_mask, SIGTERM);
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	ft_printf("%i\n", getpid());
	while (1)
	{
	}
	return (0);
}
