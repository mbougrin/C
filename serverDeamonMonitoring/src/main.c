/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:11:28 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 13:14:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			sighandler(int nb)
{
	if (nb == SIGINT)
	{
		writelog("ending deamon", PATH);
		freestc();
		exit(-1);
	}
}

void			ft_signal(void)
{
	signal(SIGINT, sighandler);
}

void			background(void)
{
	t_stc	*stc;

	stc = singleton(NULL);
	if (stc->av.v == false)
	{
		pid_t	child;

		child = fork();
		if (child < 0)
			exit(1);
		if (child > 0)
			exit(0);
		freopen("/dev/null", "r", stdin);
		freopen("/dev/null", "w", stdout);
		freopen("/dev/null", "w", stderr);
	}	
}

int				main(int ac, char **av)
{
	t_stc	*stc;

	(void)ac;
	writelog("starting deamon", PATH);
	initstc();
	parseav(av);
	background();
	ipconnect();
	stc = singleton(NULL);
	createsocket();
	ft_signal();
	mainloop();
	writelog("ending deamon", PATH);
	freestc();
	return (0);
}
