/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 21:42:50 by mbougrin          #+#    #+#             */
/*   Updated: 2014/10/31 06:15:28 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_draw_background(int r, int g, int b, int a)
{
	if (SDL_SetRenderDrawColor(ft_getrenderer(), r, g, b, a) < 0)
	{
		ft_putstr_fd("SetRenderDrawColor error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
	SDL_RenderClear(ft_getrenderer());
}

void		ft_draw_rect(void)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (SDL_RenderDrawRect(ft_getrenderer(), &struct_sdl->pos) < 0)
	{
		ft_putstr_fd("SetRenderDrawRect error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}

void		ft_draw_point(int x, int y)
{
	if (SDL_RenderDrawPoint(ft_getrenderer(), x, y) < 0)
	{
		ft_putstr_fd("SetRenderDrawPoint error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}

void		ft_draw_line(int x1, int y1, int x2, int y2)
{
	if (SDL_RenderDrawLine(ft_getrenderer(), x1, y1, x2, y2) < 0)
	{
		ft_putstr_fd("SetRenderDrawLine error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}
