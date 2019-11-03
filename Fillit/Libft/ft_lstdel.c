/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 03:14:04 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/07 05:01:28 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tempnode;

	if (*alst)
	{
		tempnode = *alst;
		while (*alst)
		{
			tempnode = tempnode->next;
			ft_lstdelone(alst, del);
			*alst = tempnode;
		}
	}
}
