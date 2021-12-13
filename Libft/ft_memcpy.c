/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:25:39 by tgresle           #+#    #+#             */
/*   Updated: 2019/12/03 14:26:21 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (!src && !dst)
		return (NULL);
	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}
