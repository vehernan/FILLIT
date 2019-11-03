/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 05:07:22 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/10 18:27:24 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*s1;

	i = 0;
	if (!(s1 = ((void *)malloc(sizeof(void) * size))))
		return (NULL);
	while (i < size)
	{
		s1[i] = 0;
		i++;
	}
	return ((void *)s1);
}
