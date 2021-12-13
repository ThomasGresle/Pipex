/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:09:50 by tgresle           #+#    #+#             */
/*   Updated: 2019/12/19 13:44:14 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**begin;
	t_list	*new;

	begin = NULL;
	if (lst && f)
	{
		while (lst != NULL)
		{
			if (begin == NULL && lst)
			{
				new = ft_lstnew(f(lst));
				lst = lst->next;
				begin = &new;
			}
			ft_lstadd_back(begin, ft_lstnew(f(lst)));
			if (!(ft_lstlast(*begin)))
			{
				ft_lstclear(begin, del);
				return (0);
			}
			lst = lst->next;
		}
	}
	return (*begin);
}
