/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:00:01 by tgresle           #+#    #+#             */
/*   Updated: 2019/11/28 15:08:24 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	**temp;

	temp = &lst;
	if (lst && f)
	{
		while ((*temp) != NULL)
		{
			f((*temp)->content);
			temp = &(*temp)->next;
		}
	}
}
