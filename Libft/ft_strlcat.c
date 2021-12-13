/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:10:54 by tgresle           #+#    #+#             */
/*   Updated: 2019/11/22 19:42:56 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	if (dstsize < 1)
		return (k);
	while (src[j] && (i + j) < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j != 0)
		dst[i + j] = '\0';
	if (dstsize < i)
		return (dstsize + k);
	else
		return (i + k);
}
