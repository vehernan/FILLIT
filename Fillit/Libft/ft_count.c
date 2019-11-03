/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:16:55 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/09 03:47:40 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(char const *str, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			wc++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (wc);
}
