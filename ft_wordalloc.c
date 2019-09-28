/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:10:08 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:49:47 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wordalloc(char const *s, char c)
{
	char	*word;
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (s[l] != c && s[l])
		l++;
	if (!(word = (char*)malloc(sizeof(char*) * l)))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
