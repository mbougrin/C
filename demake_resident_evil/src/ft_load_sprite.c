/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/23 20:35:54 by mbougrin          #+#    #+#             */
/*   Updated: 2014/10/30 15:29:30 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_load_sprite(const char *sprite)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->sprite = NULL;
	if ((struct_sdl->sprite = SDL_LoadBMP(sprite)) == NULL)
	{
		ft_putstr_fd("SDL_LoadBMP error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
	if ((struct_sdl->texture = SDL_CreateTextureFromSurface(ft_getrenderer(), \
		struct_sdl->sprite)) == 0)
	{
		ft_putstr_fd("SDL_CreateTextureFromSurface error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
	if ((SDL_RenderCopy(ft_getrenderer(), struct_sdl->texture, NULL, \
		&struct_sdl->pos)) < 0)
	{
		ft_putstr_fd("SDL_RenderCopy error ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
	SDL_DestroyTexture(struct_sdl->texture);
}
