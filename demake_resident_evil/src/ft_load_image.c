/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 03:15:13 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/02 03:18:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_load_image(const char *str)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->texture = IMG_LoadTexture(ft_getrenderer(), str);
	if (struct_sdl->texture == NULL)
	{
		ft_putstr_fd("IMG_LoadTexture error ", 2);
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
