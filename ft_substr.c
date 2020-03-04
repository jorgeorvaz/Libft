/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:01:34 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/04 12:56:23 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL || len == 0 || start > ft_strlen(s))
		return (NULL);
	if (!(ptr = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && *s)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
