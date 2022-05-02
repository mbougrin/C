/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:02:52 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 19:12:39 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				process(int cs)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				fd;
	char			**split;
	char			*line = NULL;

	dirp = opendir("/proc");
	while ((dp = readdir(dirp)))
	{
		if (dp->d_type == DT_DIR && dp->d_name[0] != '.')
		{
			char	buff[256];
			
			ft_bzero(buff, 256);
			ft_strcat(buff, "/proc/");
			ft_strcat(buff, dp->d_name);
			ft_strcat(buff, "/status");
			fd = open(buff, O_RDONLY);
			if (fd != -1)
			{
				while (get_next_line(fd, &line))
				{
					if (ft_strncmp(line, "Name", 4) == 0)
					{
						split = ft_strsplit(line, ':');
						ft_putstr_fd(ft_strtrim(split[1]), cs);
						ft_putchar_fd(' ', cs);
						ft_strstrdel(split);
					}
					else if (ft_strncmp(line, "State", 5) == 0)
					{
						split = ft_strsplit(line, ':');
						char **splitspace;
						splitspace = ft_strsplit(ft_strtrim(split[1]), ' ');
						ft_putstr_fd(splitspace[1], cs);
						ft_strstrdel(split);
						ft_strstrdel(splitspace);
						ft_putchar_fd(' ', cs);
					}
					ft_strdel(&line);
				}
				close(fd);
				ft_putchar_fd('\n', cs);
			}
		}
	}
	closedir(dirp);
}

void				version(int cs)
{
	int fd = open("/proc/version", O_RDONLY);
	char *line = NULL;

	if (fd == -1)
		return ;
	while (get_next_line(fd, &line))
	{
		ft_putendl_fd(line, cs);
		ft_strdel(&line);
	}
	close(fd);
}

void				meminfo(int cs)
{
	int fd = open("/proc/meminfo", O_RDONLY);
	char *line = NULL;

	if (fd == -1)
		return ;
	while (get_next_line(fd, &line))
	{
		if (ft_strncmp(line, "MemTotal", 8) == 0)
			ft_putendl_fd(line, cs);
		if (ft_strncmp(line, "MemFree", 7) == 0)
			ft_putendl_fd(line, cs);
		if (ft_strncmp(line, "MemAvailable", 12) == 0)
			ft_putendl_fd(line, cs);
		ft_strdel(&line);
	}
	close(fd);
}

void				cpuinfo(int cs)
{
	int	core = 0;
	int	fd = open("/proc/cpuinfo", O_RDONLY);
	bool cpu = false;
	char *line = NULL;

	if (fd == -1)
		return ;
	while (get_next_line(fd, &line))
	{
		if (ft_strncmp(line, "processor", 9) == 0)
			core++;
		if (ft_strncmp(line, "model name", 10) == 0 \
				&& cpu == false)
		{
			cpu = true;
			char **split = ft_strsplit(line, ':');
			ft_putendl_fd(ft_strtrim(split[1]), cs);
			ft_strstrdel(split);
		}
		ft_strdel(&line);
	}
	char *nb = ft_itoa(core);

	write(cs, nb, ft_strlen(nb));
	write(cs, " core\n", 6);
	ft_strdel(&nb);
	close(fd);
}
