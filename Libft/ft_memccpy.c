/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:18:06 by tgresle           #+#    #+#             */
/*   Updated: 2019/11/19 18:13:05 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (i < n && a[i] != (unsigned char)c)
	{
		b[i] = a[i];
		i++;
	}
	if (a[i] == (unsigned char)c)
	{
		b[i] = a[i];
		i++;
		return (&b[i]);
	}
	else
		return (0);
}
