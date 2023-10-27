/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:23:55 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/27 14:26:17 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_sig(__pid_t pid, int sig, char *str)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("[INFO] It was not possible to send a ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" signal to the server\n", 1);
	}
}

void	send_char(int pid, unsigned char c)
{
	int	len;

	len = 7;
	while (len >= 0)
	{
		if (c >> len & 1)
			send_sig(pid, SIGUSR1, "SIGUSR1");
		else
			send_sig(pid, SIGUSR2, "SIGUSR2");
		len--;
		usleep(256);
	}
}

void	print(int sig)
{
	if (sig == SIGUSR1)
		write(1, "bt!", 3);
	else if (sig == SIGUSR2)
		write(1, "ch\n", 3);
}

void	format_error(void)
{
	write(1, "Wrongly formatted - ./client <pid> <string>\n", 44);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	int					i;
	struct sigaction	sig_print;

	sig_print.sa_handler = print;
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	if (argc <= 2 || argc > 3)
		format_error();
	pid = ft_atoi(argv[1]);
	if ((pid == 0 && ft_strncmp(argv[1], "0", 4)) || pid < 0)
		format_error();
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i++]);
		usleep(256);
	}
	return (0);
}
