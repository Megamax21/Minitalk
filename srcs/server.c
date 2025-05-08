/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:59:39 by ml-hote           #+#    #+#             */
/*   Updated: 2025/05/07 18:12:27 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <unistd.h>

t_data	g_data;

char	ft_bits_to_char(int bits[8])
{
	char	result;
	int		i;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result <<= 1;
		result |= (bits[i] & 1);
		i++;
	}
	return ((char)result);
}

void	ft_store_char(char c)
{
	char	*new_buf;

	if (g_data.buf_index >= g_data.buf_size - 1)
	{
		new_buf = malloc(g_data.buf_size * 2);
		if (!new_buf)
			exit(1);
		ft_memcpy(new_buf, g_data.str, g_data.buf_size);
		safe_free(g_data.str);
		g_data.str = new_buf;
		g_data.buf_size *= 2;
	}
	g_data.str[g_data.buf_index++] = c;
}

void	ft_handle_complete_char(char c, int sender_pid)
{
	if (c == '\0')
	{
		g_data.str[g_data.buf_index] = '\0';
		ft_printf("%s\n", g_data.str);
		kill(sender_pid, SIGUSR1);
		kill(sender_pid, SIGUSR2);
		g_data.buf_index = 0;
	}
	else
	{
		ft_store_char(c);
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	char	c;

	(void)context;
	if (signal == SIGUSR1)
		g_data.c_buffer[g_data.i] = 0;
	else if (signal == SIGUSR2)
		g_data.c_buffer[g_data.i] = 1;
	else if (signal == SIGINT)
	{
		safe_free(g_data.str);
		exit(130);
	}
	g_data.i++;
	if (g_data.i == 8)
	{
		c = ft_bits_to_char(g_data.c_buffer);
		ft_handle_complete_char(c, info->si_pid);
		ft_memset(g_data.c_buffer, 0, sizeof(g_data.c_buffer));
		g_data.i = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	g_data.buf_size = 1024;
	g_data.buf_index = 0;
	g_data.str = malloc(g_data.buf_size);
	if (!g_data.str)
		return (1);
	g_data.str[0] = '\0';
	g_data.i = 0;
	sigemptyset(&g_data.sa.sa_mask);
	g_data.sa.sa_flags = SA_SIGINFO;
	g_data.sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &g_data.sa, NULL) == -1
		|| sigaction(SIGUSR2, &g_data.sa, NULL) == -1
		|| sigaction(SIGINT, &g_data.sa, NULL) == -1)
		return (1);
	ft_printf("Server is ready - PID : %d\n", getpid());
	while (1)
		pause();
	safe_free(g_data.str);
	return (0);
}
