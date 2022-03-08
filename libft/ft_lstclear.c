/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:27:09 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/09/20 13:10:50 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*begin_lst;

	if (*lst && lst)
	{
		begin_lst = *lst;
		while (begin_lst)
		{
			current = begin_lst;
			begin_lst = begin_lst->next;
			del(current->content);
			free(current);
		}
		*lst = NULL;
	}
}
