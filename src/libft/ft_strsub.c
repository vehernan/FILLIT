/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 06:39:26 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/11 16:30:23 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*freshsub;

	if (s == NULL)
		return (0);
	i = 0;
	freshsub = ft_strnew(len);
	if (freshsub == NULL)
		return (NULL);
	while (i < len)
	{
		freshsub[i] = s[start + i];
		i++;
	}
	freshsub[i] = '\0';
	return (freshsub);
}
