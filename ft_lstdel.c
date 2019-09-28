/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:49:35 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 15:50:00 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL || del == NULL)
		return ;
	if (&((*alst)->next) != NULL)
		ft_lstdel(&((*alst)->next), del);
	del(*alst, sizeof((*alst)));
	(*alst) = NULL;
}
