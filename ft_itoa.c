/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:06:00 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/06 14:18:01 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_size_integer(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i++;
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char				*ft_char(char *ptr, long n, size_t n_size)
{
	size_t		i;

	i = n_size - 1;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		ptr[i--] = (n % 10) + '0';
		n = n / 10;
	}
	ptr[n_size] = '\0';
	return (ptr);
}

char					*ft_itoa(int n)
{
	size_t			n_size;
	char			*ptr;
	long			number;

	number = n;
	n_size = ft_size_integer(number);
	if (!(ptr = (char *)malloc(sizeof(char) * (n_size + 1))))
		return (NULL);
	ptr = ft_char(ptr, number, n_size);
	return (ptr);
}
