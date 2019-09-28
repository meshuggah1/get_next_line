/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:56:48 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 16:33:16 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *p_dest;
	char *p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = (char *)dest;
	p_src = (char *)src;
	while (n-- > 0)
		*(p_dest++) = *(p_src++);
	return (dest);
}
