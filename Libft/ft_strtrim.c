/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:01:49 by tgresle           #+#    #+#             */
/*   Updated: 2020/01/07 21:21:20 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (c == set[i])
		return (1);
	else
		return (0);
}

static int	strlen_final(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && is_set(s1[i], set))
		i++;
	while (k >= 0 && is_set(s1[k], set))
	{
		k--;
		j++;
	}
	return (ft_strlen(s1) - i - j);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	j = 0;
	k = strlen_final(s1, set);
	if (k <= 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (k + 1));
	if (!(str))
		return (NULL);
	while (is_set(s1[i], set))
		i++;
	while (j < k)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
