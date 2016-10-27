/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 16:55:16 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 00:42:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

SDL_Surface	*(*g_ptr_function)(TTF_Font *, const char *, SDL_Color);

void		ft_init_ttf(void)
{
	if(TTF_Init() < 0)
	{
		ft_putstr_fd("TTF_init error ", 2);
		ft_putendl_fd(TTF_GetError(), 2);
		ft_free();
		exit(-1);
	}
}

static void	ft_choose_tty_quality(int nb)	
{
	if (nb == 1)
	{
		g_ptr_function = NULL;
		g_ptr_function = TTF_RenderText_Solid;
	}
	else if (nb == 2)
	{
		g_ptr_function = NULL;
		g_ptr_function = TTF_RenderText_Blended;
	}
}

void		ft_write_tty(const char* str, SDL_Rect *pos, SDL_Color *color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;
	t_sdl		*struct_sdl;

	surface = NULL;
	texture = NULL;
	struct_sdl = ft_getstruct_sdl();
	ft_choose_tty_quality(struct_sdl->param.quality_text);
	if ((surface = (*g_ptr_function)(ft_getfont(), str, *color)) == NULL)
	{
		ft_putstr_fd("TTF_RenderTextSolid error ", 2);
		ft_putendl_fd(TTF_GetError(), 2);
		ft_free();
		exit(-1);
	}
        if ((texture = SDL_CreateTextureFromSurface(ft_getrenderer(), surface)) == 0)
	{
		ft_putstr_fd("SDL_CreateTextureFromSurface error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
        SDL_FreeSurface(surface);
       	if (SDL_RenderCopy(ft_getrenderer(), texture, NULL, pos) < 0)
	{
		ft_putstr_fd("SDL_RenderCopy error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);

	}
        SDL_DestroyTexture(texture);
}
