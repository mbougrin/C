/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:47:02 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 18:48:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				initfd(void)
{
	t_stc		*stc;
	int			i;

	i = 0;
	stc = singleton(NULL);
	stc->socket.dmax = 0;
	FD_ZERO(&stc->socket.writefd);
	FD_ZERO(&stc->socket.readfd);
	while (i < stc->socket.maxsd)
	{
		if (stc->socket.fds[i].type != FD_FREE)
		{
			FD_SET(i, &stc->socket.readfd);
			if (ft_strlen(stc->socket.fds[i].buf_write) > 0)
				FD_SET(i, &stc->socket.writefd);
			stc->socket.dmax = (i > stc->socket.dmax) ? i : stc->socket.dmax;
		}
		++i;
	}
}

void	do_select(void)
{
	t_stc				*stc;

	stc = singleton(NULL);
	stc->socket.r = select(stc->socket.dmax + 1, &stc->socket.readfd, &stc->socket.writefd, NULL, NULL);
}

void	check_fd(void)
{
	int	i;
	t_stc				*stc;

	stc = singleton(NULL);
	i = 0;
	while ((i < stc->socket.maxsd) && (stc->socket.r > 0))
	{
		if (FD_ISSET(i, &stc->socket.readfd))
			stc->socket.fds[i].fct_read(i);
		if (FD_ISSET(i, &stc->socket.writefd))
			stc->socket.fds[i].fct_write(i);
		if (FD_ISSET(i, &stc->socket.readfd) || \
				FD_ISSET(i, &stc->socket.writefd))
			stc->socket.r--;
		i++;
	}
}

void				mainloop(void)
{
	while (1)
	{
		initfd();
		do_select();
		check_fd();
	}
}

void					cleanclient(t_fd *fds)
{
	fds->type = FD_FREE;
	fds->fct_read = NULL;
	fds->fct_write = NULL;
}

void					clientread(int cs)
{
	int					r;
	t_stc				*stc;

	stc = singleton(NULL);
	r = recv(cs, stc->socket.fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		cleanclient(&stc->socket.fds[cs]);
	}
	else
	{
		ft_putstr(stc->socket.fds[cs].buf_read);
		if (ft_strcmp(stc->socket.fds[cs].buf_read, "ping\n") == 0)
		{
			ping(stc->addr);
			writelog("ping success", PATH);
			ft_putendl("ping success");
			stc->socket.fds[cs].ret.ping = true;
			stc->socket.fds[cs].fct_write(cs);
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "log\n") == 0)
		{
			printlog(cs);
			writelog("log success", PATH);
			ft_putendl("log success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "status\n") == 0)
		{
			write(cs, "1", 1);
			writelog("status success", PATH);
			ft_putendl("status success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "cpuinfo\n") == 0)
		{
			cpuinfo(cs);
			writelog("cpuinfo success", PATH);
			ft_putendl("cpuinfo success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "meminfo\n") == 0)
		{
			meminfo(cs);
			writelog("meminfo success", PATH);
			ft_putendl("meminfo success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "version\n") == 0)
		{
			version(cs);
			writelog("version success", PATH);
			ft_putendl("version success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "process\n") == 0)
		{
			process(cs);
			writelog("process success", PATH);
			ft_putendl("process success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "help\n") == 0)
		{
			write(cs, "----------\n", 11);
			write(cs, "log\n", 4);
			write(cs, "ping\n", 5);
			write(cs, "status\n", 7);
			write(cs, "cpuinfo\n", 8);
			write(cs, "meminfo\n", 8);
			write(cs, "version\n", 8);
			write(cs, "process\n", 8);
			write(cs, "quit\n", 5);
			write(cs, "----------\n", 11);
			writelog("help success", PATH);
			ft_putendl("help success");
		}
		else if (ft_strcmp(stc->socket.fds[cs].buf_read, "quit\n") == 0)
		{
			writelog("request quit", PATH);
			ft_putendl("request quit");
			freestc();
			exit(0);
		}
		ft_strclr(stc->socket.fds[cs].buf_read);
	}
}

void					clientwrite(int cs)
{
	t_stc				*stc;

	stc = singleton(NULL);
	if (stc->socket.fds[cs].ret.ping == true)
	{
		writeping(cs);
		stc->socket.fds[cs].ret.ping = false;
	}
}

void					acceptclient(int i)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	t_stc				*stc;

	stc = singleton(NULL);
	(void)i;
	csin_len = sizeof(csin);
	if ((cs = accept(stc->socket.sd, (struct sockaddr *)&csin, &csin_len)) == -1)
		accepterror();
	cleanclient(&stc->socket.fds[cs]);
	stc->socket.fds[cs].type = FD_CLIENT;
	stc->socket.fds[cs].fct_read = &clientread;
	stc->socket.fds[cs].fct_write = &clientwrite;
	stc->socket.fds[cs].ret.ping = false;
	stc->socket.fds[cs].ret.log = false;
}

void					createsocket(void)
{
	t_stc				*stc;

	stc = singleton(NULL);
	stc->socket.maxsd = 254;
	stc->socket.fds = (struct s_fd *)malloc(sizeof(struct s_fd) * stc->socket.maxsd);
	if ((stc->socket.sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		socketerror();
	stc->socket.sin.sin_port = htons(stc->av.port);
	stc->socket.sin.sin_addr.s_addr = htonl(INADDR_ANY);
	stc->socket.sin.sin_family = AF_INET;
	bind(stc->socket.sd, (const struct sockaddr *)&stc->socket.sin, sizeof(stc->socket.sin));
	listen(stc->socket.sd, 42);
	stc->socket.fds[stc->socket.sd].type = FD_SERV;
	stc->socket.fds[stc->socket.sd].fct_read = &acceptclient;
}
