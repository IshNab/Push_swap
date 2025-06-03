/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:49 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 16:35:33 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			str++;
		while (*str && *str != c)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	position = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[position] == c)
		position++;
	while ((str[position + len] != c) && str[position + len])
		len++;
	next_word = malloc ((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[position] != c) && str[position])
		next_word[i++] = str[position++];
	next_word[i] = '\0';
	return (next_word);
}

char **ft_split(char *str, char c)
{
	int		words;
	char	**result_array;
	int		i;

	i = 0;
	words = word_count(str, c);
	if (!words)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words + 2));
	if (!result_array)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(str, c);
	}
	result_array[i] = NULL;
	return (result_array);
}
