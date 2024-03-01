/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:11 by chayashi          #+#    #+#             */
/*   Updated: 2024/02/29 14:12:43 by chayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void) context;
	if (signum == SIGUSR1)
		c |= (0 << i);
	else if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			kill(siginfo->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (pid < 0)
	{
		ft_printf("PIN ERROR\n");
		return (1);
	}
	ft_printf("%d\n", pid);
	while (1)
	{
	
		if (sigaction(SIGUSR1, &sa, NULL) < 0)
			ft_printf("PIN ERROR\n");	
		else if (sigaction(SIGUSR2, &sa, NULL) < 0)
			ft_printf("PIN ERROR\n");
		pause();
	}
	return (0);
}
