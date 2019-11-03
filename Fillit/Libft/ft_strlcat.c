/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 05:33:41 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/07 04:52:00 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t x;

	i = 0;
	j = 0;
	x = 0;
	while (dst[i])
		i++;
	if (i < dstsize)
	{
		while (src[j] && i + j + 1 < dstsize)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	else
		x = i - dstsize;
	return (i + ft_strlen(src) - x);
}
