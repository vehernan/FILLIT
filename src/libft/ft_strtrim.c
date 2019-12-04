/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 06:40:03 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/06 00:35:52 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*freshcop;

	start = 0;
	if (s == NULL)
		return (NULL);
	while (((s[start] == ' ') || (s[start] == '\n')
				|| (s[start] == '\t')) && (s[start] != '\0'))
		start++;
	len = ft_strlen(s);
	while (((s[len - 1] == ' ') || (s[len - 1] == '\n')
				|| (s[len - 1] == '\t')) && (s[start] != '\0'))
		len--;
	freshcop = ft_strsub(s, start, len - start);
	if (freshcop)
		return (freshcop);
	return (NULL);
}
