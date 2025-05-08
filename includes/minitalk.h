/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:54:57 by ml-hote           #+#    #+#             */
/*   Updated: 2025/05/07 18:06:49 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	struct sigaction	sa;
	int					c_buffer[8];
	int					i;
	int					word_end;
	int					buf_index;
	int					buf_size;
	char				*str;
}	t_data;

#endif
