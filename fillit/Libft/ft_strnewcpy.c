/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:51:26 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/13 10:57:45 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strnewcpy( string) --> copy of string
**  given a string.
**  a copy is made
*/

char	*ft_strnewcpy(char *str)
{
	char *temp;

	if (str == NULL)
		return (NULL);
	temp = ft_memalloc(ft_strlen(str));
	ft_strcpy(temp, str);
	return (temp);
}
