/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:31:28 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 18:11:38 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				i;

	if (dst == src)
		return (dst);
	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (src1 < dst1)
		while (++i <= len)
			dst1[len - i] = src1[len - i];
	else
		while (len-- > 0)
		{
			dst1[i] = src1[i];
			i++;
		}
	return (dst);
}
