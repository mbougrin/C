/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:40:27 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 12:56:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				printlog(int cs)
{
	char	*line;
	int		fd;

	if ((fd = open(PATH, O_RDONLY)) == -1)
		openerror();
	while (get_next_line(fd, &line))
	{
		ft_putendl_fd(line, cs);
		free(line);
	}
	close(fd);
}

void				writelog(char *str, char *path)
{
	int			fd;
	char		buff[128];
	time_t 		t;
	int			i;
		
	i = 0;
	ft_strclr(buff);
	t = time(NULL); 
	if ((fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
		openerror();
	ft_strcat(buff, ctime(&t));
	ft_strcat(buff, str);
	while (buff[i])
	{
		if (buff[i] == '\n')
			buff[i] = ' ';
		i++;
	}
	ft_putendl_fd(buff, fd);
	close(fd);
}
