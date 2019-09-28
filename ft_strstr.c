/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:17:24 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:49:31 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int j;

	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		j = 0;
		while (to_find[j] == str[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
