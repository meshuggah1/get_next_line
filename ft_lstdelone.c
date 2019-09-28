/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:50:10 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 16:04:54 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**static void     del(void *ptr, size_t s)
**{
**   free(ptr);
**   (void)s;
**}
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(alst[0]);
	*alst = NULL;
	return ;
}
/*
**static int main(void)
**{
**    t_list **blist;
**
**    blist = (t_list **)malloc(sizeof(t_list **));
**    blist[0] = (t_list *)malloc(sizeof(t_list));
**    blist[0]->content = (int *)malloc(sizeof(int));
**    blist[0]->content_size = sizeof(int);
**    blist[0]->next= NULL;
**    *((int *)blist[0]->content) = 25;
**    ft_lstdelone(&t, del);
**}
*/
