/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:49:22 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:53:45 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;

	neg = 1;
	res = 0;
	while (*str == '\f' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res > 9223372036854775807 && neg == 1)
			return (-1);
		else if (res > 9223372036854775807 && neg == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (int)(res * neg);
}
/*
**static int main(void)
**{
**    printf("%d", ft_atoi("92233720368547758075"));
**    printf("\n");
**    printf("%d", ft_atoi("-92233720368547758075"));
**    printf("\n");
**    printf("%d", ft_atoi("-45760076"));
**    printf("\n");
**    printf("%d", ft_atoi("0"));
**    printf("\n");
**    printf("%d", ft_atoi("00760076"));
**    printf("\n");
**}
*/
