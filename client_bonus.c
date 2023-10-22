/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:23:55 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/22 18:43:30 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_char(int pid, unsigned char c)
{
	int	len;

	len = 7;
	while (len >= 0)
	{
		if (c >> len & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len--;
		usleep(100);
	}
}

void	print(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("1!");
	else if (sig == SIGUSR2)
		ft_printf("2!\n");
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	char				*str;
	int					i;
	struct sigaction	sig_print;

	sig_print.sa_handler = print;
	sigaction(SIGUSR1, &sig_print, NULL);
	sigaction(SIGUSR2, &sig_print, NULL);
	if (argc <= 2 || argc > 3)
	{
		ft_printf("Wrongly formatted - ./client <pid> <string>");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		usleep(100);
		i++;
	}
	return (0);
}
