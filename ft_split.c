/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:07 by cdupuis           #+#    #+#             */
/*   Updated: 2023/08/13 17:30:45 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freesplit(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != c && s[i] != '\0')
		{
			count++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (count);
}

static char	*getstr(char const *s, int min, int max)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ((max - min) + 1));
	if (!str)
		return (NULL);
	while (min <= max - 1)
	{
		str[i] = s[min];
		i++;
		min++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		lenmin;
	char	**str;

	i = 0;
	j = 1;
	str = malloc(sizeof(char *) * (wordcount(s, c) + 2));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		lenmin = i;
		while (s[i] == c && s[i] != '\0')
			i++;
		lenmin = i;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			str[j++] = getstr(s, lenmin, i);
		}
	}
	str[j] = NULL;
	return (str);
}
