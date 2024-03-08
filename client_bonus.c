/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:19 by chayashi          #+#    #+#             */
/*   Updated: 2024/03/08 15:47:56 by chayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & 128) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		bit++;
		usleep(500);
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received successfully!\n");
}

void	send_message(char *str, int pid)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("ERROR\nYou must write ./client <PID> <\"Message\">\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid < 0 || !str)
	{
		ft_printf("ERROR: Invalid arguments!\n");
		return (1);
	}
	signal(SIGUSR1, &handler);
	send_message(str, pid);
	return (0);
}
