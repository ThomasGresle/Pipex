/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:00:46 by tgresle           #+#    #+#             */
/*   Updated: 2020/01/07 18:41:52 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char a)
{
	if (c == a)
		return (1);
	else
		return (0);
}

static int	strlensep(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static int	nbr_str(char const *s, char c)
{
	int i;
	int j;

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

static void	last_malloc(char **str, int *j)
{
	if (!(str[(*j)] = malloc(sizeof(char) * 1)))
		return ;
	str[(*j)] = 0;
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	if (!(str = malloc(sizeof(char *) * (nbr_str(s, c) + 1))))
		return (0);
	while (s[i] && strlensep(s, c, i) != 0)
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i] && !(str[j] = malloc(sizeof(char) * (strlensep(s, c, i) + 1))))
			return (0);
		while (s[i] && (is_sep(s[i], c) == 0))
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
		k = 0;
	}
	last_malloc(str, &j);
	return (str);
}
