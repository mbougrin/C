/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:36:46 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 13:12:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static t_ping	initping(void)
{
	t_ping	ping;

	ping.sd = 0;
	ping.transmitted = 0;
	ping.lost = 0;
	ping.allpacket = 0;
	ping.msmin = 0;
	ping.msmoy = 0;
	ping.msmax = 0;
	ping.allms = 0;
	ping.ipping = PING;
	ping.speedtestip = SPEEDTEST;
	ping.myip = NULL;
	return (ping);
}

static t_sock	initsock(void)
{
	t_sock	socket;

	socket.sd = 0;
	socket.r = 0;
	FD_ZERO(&socket.writefd);
	FD_ZERO(&socket.readfd);
	return (socket);
}

static t_av		initav(void)
{
	t_av	av;

	av.timeout = TIMEOUT;
	av.nbpacket = NBPACKET;
	av.v = false;
	av.port = 0;
	av.size = SIZEPACKET;
	return (av);
}

void			initstc(void)
{
	t_stc		*stc;

	if ((stc = (t_stc *)malloc(sizeof(t_stc))) == NULL)
		mallocerror();
	stc->av = initav();
	stc->ping = initping();
	stc->socket = initsock();
	stc->hints.ai_family = AF_UNSPEC;
	stc->hints.ai_socktype = SOCK_DGRAM;
	stc->hints.ai_flags = 0;
	stc->hints.ai_protocol = 0;
	singleton(stc);
}
