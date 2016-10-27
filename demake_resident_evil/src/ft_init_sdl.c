/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 16:33:38 by mbougrin          #+#    #+#             */
/*   Updated: 2014/10/31 07:40:39 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** win_sdl is a pointeur for a struct SDL_Window and initialisation as NULL
** SDL_Init is a initialisation from SDL library
** error checked and return message SDL_GetError for more information and quit SDL
** SDL_CreateWindow is a create windows SDL and parameter is value MACCRO
** error checked and return message SDL_GetError for more information and quit SDL
*/

void		ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_FLAGS) < 0)
	{
		ft_putstr_fd("SDL_Init error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}

void		ft_create_win_sdl(SDL_Window** win_sdl, int w, int h)
{
	if (w <= 0 || h <= 0)
	{
		if ((*win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, POS_WIDTH, \
		POS_HEIGHT, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd(SDL_GetError(), 2);
			ft_free();
			exit(-1);
		}

	}
	else
	{
		if ((*win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, w, \
		h, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd(SDL_GetError(), 2);
			ft_free();
			exit(-1);
		}


	}
}
