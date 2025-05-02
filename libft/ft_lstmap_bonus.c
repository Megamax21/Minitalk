/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:02:25 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/22 23:47:44 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*new_l;
	t_list	*new_n;

	if (!lst)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		if (f)
			new_n = ft_lstnew(f(lst->content));
		else
			new_n = ft_lstnew(lst->content);
		if (!new_n)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_n);
		lst = lst->next;
	}
	return (new_l);
}
