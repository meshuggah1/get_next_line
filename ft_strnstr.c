/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:54:07 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 18:55:52 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	j;
	int	true_len;

	true_len = len;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len)
	{
		j = 0;
		while (needle[j] == haystack[j] && needle[j] != '\0' && len)
		{
			j++;
			len--;
		}
		if (needle[j] == '\0')
			return ((char *)haystack);
		else
			len = --true_len;
		haystack++;
	}
	return (NULL);
}
