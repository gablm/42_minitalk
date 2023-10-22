/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:10:30 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/22 18:44:42 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print(int sig, siginfo_t *si, void *uc)
{
	static int	i;
	static int	c;

	(void)uc;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c <<= 1;
	i++;
	kill(si->si_pid, SIGUSR1);
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(si->si_pid, SIGUSR2);
		return ;
	}
}

int	main(void)
{
	struct sigaction	sig_print;

	sig_print.sa_flags = SA_SIGINFO;
	sig_print.sa_sigaction = &print;
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	ft_printf("%i\n", getpid());
	while (1)
	{
	}
	return (0);
}
