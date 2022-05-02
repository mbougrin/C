/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:41:10 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/24 17:25:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				openerror(void)
{
	ft_putendl("open error");
	freestc();
	exit(-1);
}

void				mallocerror(void)
{
	ft_putendl("malloc error");
	exit(-1);
}

void					accepterror(void)
{
	printf("accept error\n");
	freestc();
	exit(-1);
}

void					socketerror(void)
{
	printf("socket error\n");
	freestc();
	exit(-1);
}

void					setsockopterror(void)
{
	printf("setsockopt error\n");
	freestc();
	exit(-1);
}

void					addrerror(void)
{
	t_stc		*stc;

	stc = singleton(NULL);
	printf("%s: unknown host %s\n", stc->name, stc->ping.ipping);
	freestc();
	exit(-1);
}

void					connecterror(void)
{
	printf("connect error\n");
	freestc();
	exit(-1);
}

void					sendtoerror(void)
{
	printf("sendto error\n");
	freestc();
	exit(-1);
}
