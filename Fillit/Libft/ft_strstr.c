/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 01:42:28 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/10 23:23:07 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] != needle[j] && haystack[i] != '\0')
			i++;
		while (haystack[i] != '\0' && needle[j] != '\0'
				&& (haystack[i++] == needle[j++]))
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		x++;
		j = 0;
		i = x;
	}
	return (NULL);
}
