/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:51:54 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 16:05:14 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**static void    ft_free_lst(t_list *inc)
**{
**        free(inc);
**        inc = inc->next;
**        if (inc != NULL)
**            ft_free_lst(inc);
**}
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	else
		return (NULL);
}
