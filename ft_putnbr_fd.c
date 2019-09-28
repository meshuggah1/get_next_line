/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:04:41 by msimmons          #+#    #+#             */
/*   Updated: 2019/09/27 18:56:20 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mega(int fd, int n)
{
	if (n == 0)
	{
		ft_putstr_fd("0", fd);
	}
	else
	{
		ft_putstr_fd("-2", fd);
		ft_putnbr_fd(147483648, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int d;

	if (n == -2147483648 || n == 0)
	{
		mega(fd, n);
		return ;
	}
	d = 1000000000;
	while (n / d == 0)
		d /= 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (d > 0)
	{
		ft_putchar_fd(n / d + '0', fd);
		n %= d;
		d /= 10;
	}
}
/*
**int main()
**{
**    int fd = open("fileko", O_RDONLY);
**    if (fd == -1)
**        printf("error");
**    ft_putnbr_fd(0, fd);
**    ft_putnbr_fd(1, fd);
**    ft_putnbr_fd(-1, fd);
**    ft_putnbr_fd(56, fd);
**    ft_putnbr_fd(-1230, fd);
**    ft_putnbr_fd(10203, fd);
**    ft_putnbr_fd(2147483647, fd);
**    ft_putnbr_fd(-2147483648, fd);
**    #include <sys/types.h>
**    #include <sys/stat.h>
**    #include <fcntl.h>
**}
*/
