/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:51:19 by tgresle           #+#    #+#             */
/*   Updated: 2019/12/19 13:45:42 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	if (*lst && del)
	{
		while ((*lst)->next)
		{
			ptr = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(ptr, del);
		}
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
