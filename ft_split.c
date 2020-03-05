/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:11:14 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/05 13:28:33 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		meter;

	i = 0;
	meter = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				meter++;
		}
		i++;
	}
	return (meter);
}

static char	*get_words(char const *s, char c)
{
	char	*word;
	int		num_letters;
	int		i;

	num_letters = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		num_letters++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (num_letters + 1));
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

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		num_words;
	int		i;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ptr[i] = get_words(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
