/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:18:18 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/03 19:34:40 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		s1_size;
	char		*ptr;

	s1_size = ft_strlen(s1);
	if (!(ptr = malloc(s1_size + 1)))
		return (NULL);
	ptr = ft_memcpy(ptr, s1, s1_size);
	ptr[s1_size] = '\0';
	return (ptr);
}
