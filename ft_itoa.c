/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:22:55 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:19:48 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_unsign_int(int n)
{
	unsigned int	num;

	if (n < 0)
		num = (-1) * n;
	else
		num = n;
	return (num);
}

static int			ft_intlen(int n)
{
	int				len;
	unsigned int	num;

	num = ft_unsign_int(n);
	len = 0;
	if (n < 0)
		len++;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	if (n == 0)
		return (1);
	return (len);
}

char				*ft_itoa(int n)
{
	char			*res;
	unsigned int	num;
	int				charge;

	charge = ft_intlen(n);
	num = ft_unsign_int(n);
	if (!(res = (char *)malloc(sizeof(char) * (charge + 1))))
		return (NULL);
	res[charge] = '\0';
	while (charge--)
	{
		res[charge] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
