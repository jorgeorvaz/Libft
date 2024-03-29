/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:11:14 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/06 15:36:27 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_words(char const *s, char c)
{
	int	act_pos;
	int	str_count;

	act_pos = 0;
	str_count = 0;
	if (s[act_pos] == c)
		str_count--;
	while (s[act_pos] != '\0')
	{
		if (s[act_pos] == c && s[act_pos + 1] != c && s[act_pos + 1] != '\0')
			str_count++;
		act_pos++;
	}
	str_count++;
	return (str_count);
}

static char		**ft_free_array(char **ptr, size_t len)
{
	while (len--)
		free((void *)ptr[len]);
	free(ptr);
	return (NULL);
}

char			*get_words(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	int		words;
	char	**ptr;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = (char **)malloc(sizeof(char*) * (words + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(ptr[i++] = get_words(s, c)))
				return (ft_free_array(ptr, words + 1));
			while (*s && *s != c)
				s++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
