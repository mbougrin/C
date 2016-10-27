/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_font.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 16:57:49 by mbougrin          #+#    #+#             */
/*   Updated: 2014/10/30 15:27:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

TTF_Font*	g_font;

TTF_Font*	ft_getfont(void)
{
	return (g_font);
}

void		ft_init_font(const char *font, int size)
{
	if ((g_font = TTF_OpenFont(font, size)) == NULL)
	{
		ft_putstr_fd("TTF_OpenFont error ", 2);
		ft_putendl_fd(TTF_GetError(), 2);
		exit(-1);
		ft_free();
	}
}
