/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:05:59 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/10 18:13:19 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	char	*fresh;
	int		i;

	i = 1;
	len = ft_nbrc(n);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(fresh, "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		fresh[0] = '-';
	}
	if (n == 0)
		fresh[0] = '0';
	while (n > 0)
	{
		fresh[len - i++] = (n % 10) + '0';
		n /= 10;
	}
	return (fresh);
}
