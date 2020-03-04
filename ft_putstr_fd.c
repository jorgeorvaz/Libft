/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:03:36 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/04 16:11:07 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t		i;
	size_t		s_size;

	if (!s)
		return ;
	i = 0;
	s_size = ft_strlen(s);
	while (i < s_size)
		write(fd, &s[i++], 1);
}
