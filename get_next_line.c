/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimmons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:33:03 by msimmons          #+#    #+#             */
/*   Updated: 2019/11/08 19:38:47 by msimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		chars_to_line(char **line, char *strcpy, int i)
{
	char	*tmp;
	char	*tmp2;

	if (!*line || !(**line))
	{
		tmp = ft_strsub(strcpy, 0, i);
		ft_strdel(line);
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		tmp2 = ft_strsub(strcpy, 0, i);
		tmp = ft_strjoin(*line, tmp2);
		ft_strdel(line);
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
}

int			str_and_fd(char *ptr, char **line, char **o)
{
	size_t	i;
	char	*tmp;

	tmp = ft_strdup(ptr);
	i = 0;
	while (i < BUFF_SIZE && tmp[i] != '\n' && tmp[i])
		i++;
	chars_to_line(line, tmp, i);
	ft_strdel(o);
	if (tmp[i] == '\n')
	{
		*o = ft_strdup(&(tmp[i + 1]));
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

int			read_fd(int fd, char **line, char *f_list[], char buf[])
{
	int ret;

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ret = str_and_fd(buf, line, &f_list[fd]);
		ft_bzero(buf, BUFF_SIZE);
		if (ret == 1)
			break ;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*f_list[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = ft_memalloc(1);
	if (f_list[fd] && *f_list[fd])
	{
		ret = str_and_fd(f_list[fd], line, &f_list[fd]);
		if (ret)
			return (1);
	}
	ret = read_fd(fd, line, f_list, buf);
	return ((!ret && **line) ? 1 : ret);
}

/*
 * The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
 *
 * There cannot be a main function in your program.
• Do not push a Makefile.
 All heap allocated memory space must be properly freed when necessary.
• Your project cannot have memory leaks.
 */