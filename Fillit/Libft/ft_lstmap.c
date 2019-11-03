/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 04:27:11 by vehernan          #+#    #+#             */
/*   Updated: 2019/07/07 04:57:31 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *tempnode;

	if (!lst || !f)
		return (NULL);
	tempnode = f(lst);
	fresh = tempnode;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tempnode->next = f(lst)))
		{
			free(tempnode->next);
			return (NULL);
		}
		else
			tempnode = tempnode->next;
	}
	return (fresh);
}
