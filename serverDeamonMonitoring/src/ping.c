/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:21:40 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/28 16:00:32 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>


t_packet				sendpacket(t_addrinfo *addr_info)
{
	static int		count;
	t_stc			*stc;
	t_packet		packet;

	stc = singleton(NULL);
	ft_bzero(&packet, sizeof(packet));
	packet.hdr.type = ICMP_ECHO;
	packet.hdr.un.echo.id = getpid();
	packet.hdr.un.echo.sequence = count + 1;
	packet.hdr.checksum = checksum(&packet, sizeof(packet));
	if (sendto(stc->ping.sd, &packet, sizeof(packet), 0, addr_info->ai_addr, \
				sizeof(*addr_info->ai_addr)) <= 0)
		sendtoerror();
	count++;
	return (packet);
}

void					statms(double ms)
{
	t_stc		*stc;

	stc = singleton(NULL);
	if (stc->ping.msmin == 0)
		stc->ping.msmin = ms;
	else if (stc->ping.msmin > ms)
		stc->ping.msmin = ms;
	if (stc->ping.msmax == 0)
		stc->ping.msmax = ms;
	else if (stc->ping.msmax < ms)
		stc->ping.msmax = ms;
	stc->ping.allms += ms;
	stc->ping.msmoy = stc->ping.allms / stc->ping.transmitted;
}

void					recvpacket(struct timeval start, struct timeval end\
		, t_packet packet)
{
	t_stc				*stc;
	double				ms;
	struct icmp			*pkt;
	struct iphdr		*iphdr;
	char				buff[128];
	char				*tmp;

	stc = singleton(NULL);
	gettimeofday(&end, NULL);
	ms = (double)((end.tv_sec - start.tv_sec) * 1000.0f);
	ms += (double)((end.tv_usec - start.tv_usec) / 1000.0f);
	statms(ms);
	printf("%f ms %f msmin %f msmax %f msmoy %f allms\n", ms,
			stc->ping.msmin, stc->ping.msmax,
			stc->ping.msmoy, stc->ping.allms);
	iphdr = (struct iphdr *)&packet;
	pkt = (struct icmp *)(&packet + (iphdr->ihl << 2));
	ft_strclr(buff);
	if (pkt->icmp_type == ICMP_ECHOREPLY)
	{
		ft_strcpy(buff, "packet transmitted ");
		tmp = ft_itoa((int)ms);
		ft_strcat(buff, tmp);
		ft_strdel(&tmp);
		ft_strcat(buff, " ms");
		writelog(buff, PATH);
		stc->ping.transmitted++;
	}
	else
	{
		ft_strcpy(buff, "packet transmitted ");
		tmp = ft_itoa((int)ms);
		ft_strcat(buff, tmp);
		ft_strdel(&tmp);
		ft_strcat(buff, " ms");
		writelog(buff, PATH);
		stc->ping.transmitted++;
	}
}

void					socketconfig(void)
{
	t_stc			*stc;
	const int		val = 255;

	stc = singleton(NULL);
	stc->ping.sd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (stc->ping.sd < 0)
		socketerror();
	if (setsockopt(stc->ping.sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
		setsockopterror();
}

void					timeout(void)
{
	t_stc			*stc;
	struct timeval	timeout;

	stc = singleton(NULL);
	timeout.tv_sec = stc->av.timeout;
	timeout.tv_usec = 0;
	setsockopt(stc->ping.sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, \
			sizeof(struct timeval));
}

static void				resetping(void)
{
	t_stc			*stc;

	stc = singleton(NULL);
	stc->ping.transmitted = 0;
	stc->ping.lost = 0;
	stc->ping.allpacket = 0;
	stc->ping.msmin = 0;
	stc->ping.msmax = 0;
	stc->ping.msmoy = 0;
	stc->ping.allms = 0;
}

void					ping(t_addrinfo *addr_info)
{
	int				i;
	t_stc			*stc = singleton(NULL);
	char			size[stc->av.size - sizeof(t_icmphdr)];
	t_sockaddr_in	r_addr;
	t_packet		packet;
	struct timeval 	start;
	struct timeval 	end;
	int				len;

	resetping();
	i = 0;
	packet.msg = size;
	socketconfig();
	while (stc->av.nbpacket > i)
	{
		len = sizeof(r_addr);
		stc->ping.allpacket++;
		sendpacket(addr_info);
		gettimeofday(&start, NULL);
		timeout();
		if (recvfrom(stc->ping.sd, &packet, sizeof(packet), 0, \
					(t_sockaddr*)&r_addr, (socklen_t *)&len) > 0)
			recvpacket(start, end, packet);
		else
		{
			writelog("packet not send", PATH);
			stc->ping.lost++;
		}
		i++;
	}
	close(stc->ping.sd);
}

void					ipconnect(void)
{
	t_stc		*stc;
	t_addrinfo	*tmp;
	t_addrinfo	*result;
	int			sd;

	stc = singleton(NULL);
	sd = 0;
	if ((getaddrinfo(stc->ping.ipping, NULL, &stc->hints, &result)) != 0)
		addrerror();
	tmp = result;
	while (tmp != NULL)
	{
		sd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
		if (sd == -1)
			continue ;
		if (connect(sd, tmp->ai_addr, tmp->ai_addrlen) != -1)
		{
			close(sd);
			break ;
		}
		close(sd);
		tmp = tmp->ai_next;
	}
	if (tmp == NULL)
		connecterror();
	stc->addr = tmp;
}
