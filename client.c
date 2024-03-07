/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:19 by chayashi          #+#    #+#             */
/*   Updated: 2024/03/07 13:53:31 by chayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int		i;
	int		bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received successfully!\n");
}

void	send_message(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
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
	send_message(pid, str);
	return (0);
}
