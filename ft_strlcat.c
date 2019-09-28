/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:20:33 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:29:37 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t ld;
	size_t j;
	size_t i;
	size_t ls;

	ls = ft_strlen(src);
	j = 0;
	ld = ft_strlen(dst);
	i = ld;
	if (n < ld + 1)
		return (ls + n);
	if (n > ld + 1)
	{
		while (src[j] && i < n - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (ld + ls);
}
