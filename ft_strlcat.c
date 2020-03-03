/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordonez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:29:37 by jordonez          #+#    #+#             */
/*   Updated: 2020/03/03 19:56:00 by jordonez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		src_size;
	size_t		dst_size;
	size_t		cont_dst;
	size_t		cont_src;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	cont_dst = dst_size;
	cont_src = 0;
	if (dstsize <= dst_size)
		src_size += dstsize;
	else
		src_size += dst_size;
	while (src[cont_src] && cont_dst + 1 < dstsize)
	{
		dst[cont_dst] = src[cont_src];
		cont_dst++;
		cont_src++;
	}
	if (dst_size < dstsize)
		dst[cont_dst] = '\0';
	return (src_size);
}
