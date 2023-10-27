/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:10:30 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:46 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_sig(__pid_t pid, int sig, char *str)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("[INFO] It was not possible to send a ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" signal to the client\n", 1);
	}
}

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
	send_sig(si->si_pid, SIGUSR1, "SIGUSR1");
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		usleep(128);
		send_sig(si->si_pid, SIGUSR2, "SIGUSR2");
	}
}

int	main(void)
{
	struct sigaction	sig_print;

	sig_print.sa_flags = SA_SIGINFO;
	sig_print.sa_sigaction = &print;
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	ft_putstr_fd("PID ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
