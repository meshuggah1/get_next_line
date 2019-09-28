/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:03:04 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/22 11:24:19 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < (-2147483647))
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar('0' + n);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}
/*
**static int main()
**{
**    ft_putnbr(346);
**    ft_putchar('\n');
**    ft_putnbr(0);
**    ft_putchar('\n');
**    ft_putnbr(-33004060);
**    ft_putchar('\n');
**    ft_putnbr(-2147483648);
**    ft_putchar('\n');
**    ft_putnbr(-2147483649);
**    ft_putchar('\n');
**    ft_putnbr(2147483648);
**}
*/
