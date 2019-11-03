/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:38:05 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/03 16:26:15 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	i;

	i = 0;
	fresh = NULL;
	if (s1 != '\0' && s2 != '\0')
	{
		fresh = (char *)malloc(sizeof(*fresh)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (fresh == '\0')
			return (NULL);
		ft_strcpy(fresh, s1);
		ft_strcat(fresh, s2);
	}
	return (fresh);
}
