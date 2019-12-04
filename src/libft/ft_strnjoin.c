/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:14:33 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/03 18:17:52 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, int i)
{
	char *string;

	string = ft_strjoin(s1, s2);
	if (i == 1 || i == 3)
	{
		free((void*)s1);
		s1 = NULL;
	}
	else if (i == 2 || i == 3)
	{
		free((void*)s2);
		s2 = NULL;
	}
	return ((char*)string);
}
