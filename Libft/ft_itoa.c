/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:04:36 by tgresle           #+#    #+#             */
/*   Updated: 2019/11/19 17:35:40 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decades(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n / 10 >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	i = decades(n);
	j = 0;
	j = n < 0 ? 1 : 0;
	if (!(str = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	str[i-- + j] = '\0';
	if (n == -2147483648)
	{
		str[i-- + j] = 8 + '0';
		n /= 10;
	}
	if (n < 0)
		n *= -1;
	while ((i + j) >= 0)
	{
		str[i-- + j] = n % 10 + '0';
		n /= 10;
	}
	if (j == 1)
		str[0] = '-';
	return (str);
}
