/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:16:01 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/14 12:17:03 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = (ft_strlen(s1) + ft_strlen(s2));
	k = 0;
	str = malloc(sizeof(char) * (j + 1));
	if (!(str))
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_path(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], path, ft_strlen(path)) == 0)
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}

void	add_slash(char **cmd_path)
{
	int	i;

	i = 0;
	while (cmd_path && cmd_path[i])
	{
		cmd_path[i] = ft_strjoin_bis(cmd_path[i], "/");
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(str))
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (s && s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
