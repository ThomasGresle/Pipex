/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:27:20 by tgresle           #+#    #+#             */
/*   Updated: 2019/11/22 14:44:24 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	if (dst < src)
	{
		while (i < len)
		{
			b[i] = a[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			b[len] = a[len];
	}
	return (dst);
}
