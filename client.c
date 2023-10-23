/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:23:55 by gfragoso          #+#    #+#             */
/*   Updated: 2023/10/23 17:29:34 by gfragoso         ###   ########.fr       */
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

void	format_error(void)
{
	ft_printf("Wrongly formatted - ./client <pid> <string>");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	__pid_t	pid;
	int		i;

	if (argc <= 2 || argc > 3)
		format_error();
	pid = ft_atoi(argv[1]);
	if (pid == 0 && ft_strncmp(argv[1], "0", 4))
		format_error();
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i++]);
		usleep(100);
	}
	return (0);
}
