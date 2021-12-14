/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:23:03 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/14 20:41:32 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	nbr_str(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (j);
}

char	**first_malloc(const char *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *) * (nbr_str(s, c) + 1));
	if (!(str))
		return (0);
	return (str);
}

void	ft_putstr_fd(char *s)
{
	write(2, s, ft_strlen(s));
}
