/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:06:00 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/04 20:17:07 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_size_integer(long int n)
{
	long int	i;

	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char			*ft_char(char *ptr, unsigned int n,
int is_negative, long int n_size)
{
	int	i;

	i = n_size - 1 + is_negative;
	while (i >= 0)
	{
		if (i == 0 && is_negative == 1)
			ptr[i--] = '-';
		ptr[i--] = n % 10 + '0';
		n = n / 10;
	}
	ptr[n_size + 1] = '\0';
	return (ptr);
}

char				*ft_itoa(int n)
{
	long int		n_size;
	char			*ptr;
	int				is_negative;
	unsigned int	number;

	n_size = ft_size_integer(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		number = n * -1;
	}
	else
		number = n;
	if (!(ptr = (char *)malloc(sizeof(char) * (n_size + 1 + is_negative))))
		return (NULL);
	ptr = ft_char(ptr, number, is_negative, n_size);
	return (ptr);
}
