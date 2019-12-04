/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:32:00 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/10 23:37:13 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**freshsub;
	int		i;
	int		j;
	int		tw;

	if (s == NULL)
		return (0);
	i = 0;
	tw = ft_count(s, c);
	if (s == NULL || !(freshsub = (char **)malloc(sizeof(char*) * (tw + 1))))
		return (NULL);
	while (tw--)
	{
		if (!(freshsub[i] = (char*)malloc(sizeof(char) * ft_len(s, c))))
			return (NULL);
		while (*s == c && *s != '\0')
			s++;
		j = 0;
		while (*s != c && *s != '\0')
			freshsub[i][j++] = *s++;
		freshsub[i++][j] = '\0';
	}
	freshsub[i] = NULL;
	return (freshsub);
}
