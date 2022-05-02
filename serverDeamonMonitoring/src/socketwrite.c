/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:40:01 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 12:59:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				json_int(char *name, int nb, char **ret, bool check)
{
	char	*str;
	char	c[2];

	c[0] = '"';
	c[1] = '\0';
	str = ft_itoa(nb);
	ft_strcat(*ret, c);
	ft_strcat(*ret, name);
	ft_strcat(*ret, c);
	ft_strcat(*ret, " : ");
	ft_strcat(*ret, str);
	if (check == true)
		ft_strcat(*ret, ", ");
	ft_strdel(&str);
}

void				json_double(char *name, double nb, char **ret, bool check)
{
	char	str[20];
	char	*strnb;
	char	*strnext;
	double	nb2;
	char	c[2];

	ft_strclr(str);
	c[0] = '"';
	c[1] = '\0';
	strnb = ft_itoa(nb);
	nb2 = nb - ft_atoi(strnb);
	nb2 = nb2 * 1000;
	strnext = ft_itoa(nb2);

	ft_strcat(str, strnb);
	ft_strcat(str, ".");
	if (ft_strlen(strnext) < 3)
	{
		if (ft_strlen(strnext) == 2)
			ft_strcat(str,"0");
		if (ft_strlen(strnext) == 1)
			ft_strcat(str, "00");
		ft_strcat(str, strnext);
	}		
	else
		ft_strcat(str, strnext);

	ft_strcat(*ret, c);
	ft_strcat(*ret, name);
	ft_strcat(*ret, c);
	ft_strcat(*ret, " : ");
	ft_strcat(*ret, str);
	if (check == true)
		ft_strcat(*ret, ", ");
	ft_strclr(str);
	ft_strdel(&strnb);
	ft_strdel(&strnext);
}

void				json_char(char *name, char *str, char **ret, bool check)
{
	char	c[2];

	c[0] = '"';
	c[1] = '\0';
	ft_strcat(*ret, c);
	ft_strcat(*ret, name);
	ft_strcat(*ret, c);
	ft_strcat(*ret, " : ");
	ft_strcat(*ret, c);
	ft_strcat(*ret, str);
	ft_strcat(*ret, c);
	if (check == true)
		ft_strcat(*ret, ", ");
}

void				writeping(int cs)
{
	char	*ret;
	t_stc	*stc;

	ret = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	stc = singleton(NULL);
	ft_strcpy(ret, "{ ");
	json_int("Bytes", stc->av.size, &ret, true);
	json_int("TotalPacket", stc->ping.allpacket, &ret, true);
	json_int("PacketLost", (stc->ping.allpacket - \
						stc->ping.transmitted), &ret, true);
	json_double("MsMax", stc->ping.msmax, &ret, true);
	json_double("MsMin", stc->ping.msmin, &ret, true);
	json_double("MsMoy", stc->ping.msmoy, &ret, true);
	json_char("Host", PING, &ret, false);
	ft_strcat(ret, " }");
	write(cs, ret, ft_strlen(ret));
	ft_strdel(&ret);
}
