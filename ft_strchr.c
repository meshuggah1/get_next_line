/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:21:17 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:47:15 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char sym;

	sym = (char)c;
	while (*s)
	{
		if (*s == sym)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && sym == '\0')
		return ((char *)s);
	return (NULL);
}
