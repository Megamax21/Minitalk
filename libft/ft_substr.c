/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:02:38 by ml-hote           #+#    #+#             */
/*   Updated: 2024/11/14 09:34:24 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc(char **tab, char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s))
	{
		(*tab) = (char *)malloc(1 * sizeof(char));
		if (!*tab)
			return (0);
		(*tab)[0] = '\0';
		return (2);
	}
	if ((start + len) > ft_strlen(s))
		(*tab) = (char *)malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	else
		(*tab) = (char *)malloc((len + 1) * sizeof(char));
	if (!*tab)
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	int		a;

	if (!s)
		return (NULL);
	res = NULL;
	a = ft_malloc(&res, s, start, len);
	if (a == 0)
		return (NULL);
	else if (a == 2)
		return (res);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
