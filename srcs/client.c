/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:59:33 by ml-hote           #+#    #+#             */
/*   Updated: 2025/05/07 18:06:33 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <stddef.h>
#include <unistd.h>

struct sigaction	g_sa;

void	ft_handle_msg(int i, int sig_pid, char c)
{
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(sig_pid, SIGUSR2);
		else
			kill(sig_pid, SIGUSR1);
		pause();
		i--;
	}
}

static void	signal_handler(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signo == SIGUSR2)
	{
		ft_printf("Server got the message !\n");
		exit(0);
	}
}

void	ft_send_message(char *str, int sig_pid)
{
	int		i;
	size_t	j;

	j = 0;
	i = 7;
	while (j < ft_strlen(str))
	{
		ft_handle_msg(i, sig_pid, str[j]);
		j++;
	}
	ft_handle_msg(7, sig_pid, '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Usage: ./client [PID] [MESSAGE]\n", 32);
		return (1);
	}
	if (ft_atoi(argv[1]) < 0)
	{
		write(1, "Please have pity of my computer\n", 32);
		return (1);
	}
	g_sa.sa_sigaction = signal_handler;
	g_sa.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sa.sa_mask);
	sigaction(SIGUSR1, &g_sa, NULL);
	sigaction(SIGUSR2, &g_sa, NULL);
	ft_send_message(argv[2], atoi(argv[1]));
	pause();
	return (0);
}
