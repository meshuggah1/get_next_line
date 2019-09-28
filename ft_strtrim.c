/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:41:52 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:43:26 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank_cust(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	j = 0;
	len = ft_strlen(s) - 1;
	i = ft_isblank_cust(s);
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (!(res = ft_memalloc(len - i + 2)))
		return (NULL);
	while (i <= len)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
/*
**static int main()
**{
**    char const *s = "   fwr  ";
**    ft_strtrim(s);
**}
*/
