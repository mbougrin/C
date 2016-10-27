/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 16:57:12 by mbougrin          #+#    #+#             */
/*   Updated: 2014/10/30 16:06:13 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

SDL_Renderer*	g_renderer;

SDL_Renderer*	ft_getrenderer(void)
{
	return (g_renderer);
}

void		ft_init_renderer(SDL_Window *win_sdl)
{
	if ((g_renderer = SDL_CreateRenderer(win_sdl, -1, \
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC \
		)) == NULL)
	{
		ft_putstr_fd("SDL_Create_Renderer error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}
