/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:30:16 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 13:12:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void			showhelp(void)
{
	t_stc	*stc;

	stc = singleton(NULL);
	printf("%s\t-p port\n", stc->name);
	printf("\t\t-t timeout ping\n");
	printf("\t\t-s size packet\n");
	printf("\t\t-nb nb packet ping\n");
	printf("\t\t-v verbose mode\n");
	freestc();
	exit(0);
}

void				parseav(char **av)
{
	t_stc	*stc;
	int		i;

	stc = singleton(NULL);
	stc->name = av[0];
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-p") == 0 && av[i + 1] != NULL)
			stc->av.port = ft_atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-t") == 0 && av[i + 1] != NULL)
			stc->av.timeout = ft_atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-s") == 0 && av[i + 1] != NULL)
			stc->av.size = ft_atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-nb") == 0 && av[i + 1] != NULL)
			stc->av.nbpacket = ft_atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-v") == 0)
			stc->av.v = true;
		i++;
	}
	if (stc->av.port == 0)
		showhelp();
}
