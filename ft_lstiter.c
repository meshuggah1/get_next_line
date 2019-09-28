/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:51:07 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 16:01:14 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (1)
	{
		f(ptr);
		ptr = ptr->next;
		if (ptr == NULL)
			break ;
	}
}
