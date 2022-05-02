/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:28:19 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/25 01:29:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					freestc(void)
{
	t_stc	*stc;

	stc = singleton(NULL);
	close(stc->socket.sd);
	free(stc->socket.fds);
	free(stc);
	stc = NULL;
}

t_stc					*singleton(t_stc *stc)
{
	static t_stc	*tmp = NULL;

	if (stc != NULL)
		tmp = stc;
	return (tmp);
}

unsigned short			checksum(void *b, int len)
{
	unsigned short		*buf;
	unsigned int		sum;
	unsigned short		result;

	buf = b;
	sum = 0;
	result = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}

int					percentage(int nombre, int nombre2)
{
	return (((nombre2 - nombre) * 100 / nombre) * -1);
}
