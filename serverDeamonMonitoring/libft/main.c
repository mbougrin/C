/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:36:26 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/16 11:06:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			main(int ac, char **av)
{
	char	***tab;

	if (ac == 1)
		return (-1);
	tab = ft_tabsplit_paragraph(av);
	for (int i = 0 ; tab[i] ; ++i)
	{
		ft_putstrstr(tab[i]);
		ft_putchar('\n');
	}
	return (0);
}
