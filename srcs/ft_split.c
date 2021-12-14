/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:25:30 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/14 15:36:59 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	strlensep(char const *s, char c, int i)
{
	int	j;

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

static int	is_sep(char c, char a)
{
	if (c == a)
		return (1);
	else
		return (0);
}

static void	last_malloc(char **str, int *j)
{
	str[(*j)] = malloc(sizeof(char) * 1);
	if (!(str[(*j)]))
		return ;
	str[(*j)] = 0;
}

char	**ft_split(char const *s, char c)
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
	str = first_malloc(s, c);
	while (s[i] && strlensep(s, c, i) != 0)
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		str[j] = malloc(sizeof(char) * (strlensep(s, c, i) + 1));
		if (!(str[j]))
			return (0);
		while (s[i] && (is_sep(s[i], c) == 0))
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
		k = 0;
	}
	last_malloc(str, &j);
	return (str);
}
