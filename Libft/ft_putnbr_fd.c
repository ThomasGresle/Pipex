/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:34:38 by tgresle           #+#    #+#             */
/*   Updated: 2019/12/18 10:59:47 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tens(long i)
{
	long	j;

	j = 1;
	while (i >= 10)
	{
		j *= 10;
		i /= 10;
	}
	return (j);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	j;
	char	c;

	i = n;
	c = 0;
	if (fd >= 0)
	{
		if (i < 0)
		{
			c = '-';
			write(fd, &c, 1);
			i *= -1;
		}
		j = tens(i);
		while (j > 1)
		{
			c = ((i / j) + 48);
			write(fd, &c, 1);
			i %= j;
			j /= 10;
		}
		c = i + 48;
		write(fd, &c, 1);
	}
}
