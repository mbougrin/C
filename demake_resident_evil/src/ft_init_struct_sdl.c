/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_sdl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 19:20:32 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/02 02:57:33 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_sdl		*g_struct_sdl;

t_sdl		*ft_getstruct_sdl(void)
{
	return (g_struct_sdl);
}

void		ft_init_struct_sdl(void)
{
	int	i;

	i = 0;
	g_struct_sdl = NULL;
	g_struct_sdl = (t_sdl*)malloc(sizeof(t_sdl));
	g_struct_sdl->win_sdl = NULL;
	while (i <= 128)
	{
		g_struct_sdl->thread[i] = NULL;
		i++;
	}
	ft_init_sdl();
	ft_init_ttf();
	ft_create_win_sdl(&g_struct_sdl->win_sdl, 0, 0);
	ft_init_renderer(g_struct_sdl->win_sdl);
	ft_init_font("font/FreeMono.ttf", 65);
}

void		ft_init_sdl_rect(int w, int h, int x, int y)
{
	t_sdl	*struct_sdl;

	struct_sdl = NULL;
	struct_sdl = ft_getstruct_sdl();
	struct_sdl->pos.h = h;
	struct_sdl->pos.w = w;
	struct_sdl->pos.x = x;
	struct_sdl->pos.y = y;
}

void		ft_init_sdl_color(int r, int g, int b)
{
	t_sdl	*struct_sdl;

	struct_sdl = NULL;
	struct_sdl = ft_getstruct_sdl();
	struct_sdl->color.r = r;
	struct_sdl->color.g = g;
	struct_sdl->color.b = b;	
}
