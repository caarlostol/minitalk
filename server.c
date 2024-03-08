/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:11 by chayashi          #+#    #+#             */
/*   Updated: 2024/03/08 19:02:18 by chayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	i;
	static char	c;

	if (!i)
		i = 0;
	if (!c)
		c = 0;
	if (signal == SIGUSR2)
	{
		c += (128 >> i);
	}
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid < 0)
	{
		ft_printf("PID ERROR\n");
		return (1);
	}
	ft_printf("Welcome!\n");
	ft_printf("PID: %d\n", pid);
	ft_printf("------------------------------\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
