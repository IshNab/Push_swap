/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:49 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/16 13:03:51 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(const char *str, char c);
static int	word_len(const char *str, char c);
static void	*free_str(char **strs);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_substr(s, 0, word_len(s, c));
			if (!strs[i++])
				return (free_str(strs));
			s += word_len(s, c);
		}
		else
			s++;
	}
	return (strs);
}

static int	word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static int	word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			str += word_len(str, c);
		}
		else
			str++;
	}
	return (count);
}

static void	*free_str(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free (strs[i++]);
	free (strs);
	return (NULL);
}
