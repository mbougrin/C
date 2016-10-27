/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:05:21 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:05:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		ft_modify_quality(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (strcmp(struct_sdl->param.cursor->name, "High") == 0)
		struct_sdl->param.quality_text = 2;
	else if (strcmp(struct_sdl->param.cursor->name, "Low") == 0)
		struct_sdl->param.quality_text = 1;
}

void		ft_modify_sizescreen(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (strcmp(struct_sdl->param.cursor->name, "800x600") == 0)
		ft_change_sizescreen(800, 600);
	else if (strcmp(struct_sdl->param.cursor->name, "1280x1024") == 0)
		ft_change_sizescreen(1280, 1024);
	else if (strcmp(struct_sdl->param.cursor->name, "1920x1080") == 0)
		ft_change_sizescreen(1920, 1080);
	if (struct_sdl->param.fullscreen == 1)
		SDL_SetWindowFullscreen(struct_sdl->win_sdl, SDL_TRUE);

}

void		ft_modify_keyboard(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (strcmp(struct_sdl->param.cursor->name, "En") == 0)
		struct_sdl->param.keyboard = 1;
	else if (strcmp(struct_sdl->param.cursor->name, "Fr") == 0)
		struct_sdl->param.keyboard = 2;
}

void		ft_modify_fullscreen(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (strcmp(struct_sdl->param.cursor->name, "Off") == 0)
	{
		SDL_SetWindowFullscreen(struct_sdl->win_sdl, SDL_FALSE);
		struct_sdl->param.fullscreen = 0;
	}
	else if (strcmp(struct_sdl->param.cursor->name, "On") == 0)
	{
		SDL_SetWindowFullscreen(struct_sdl->win_sdl, SDL_TRUE);
		struct_sdl->param.fullscreen = 1;
	}
}

void		ft_modify_brightness(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (strcmp(struct_sdl->param.cursor->name, "0") == 0)
	{
		SDL_SetWindowBrightness(struct_sdl->win_sdl, struct_sdl->param.brightness_default);
		struct_sdl->param.brightness = struct_sdl->param.brightness_default;
	}
	else if (strcmp(struct_sdl->param.cursor->name, "1") == 0)
	{
		SDL_SetWindowBrightness(struct_sdl->win_sdl, struct_sdl->param.brightness_default + 1);
		struct_sdl->param.brightness = struct_sdl->param.brightness_default + 1;
	}	
	else if (strcmp(struct_sdl->param.cursor->name, "2") == 0)
	{
		SDL_SetWindowBrightness(struct_sdl->win_sdl, struct_sdl->param.brightness_default + 2);
		struct_sdl->param.brightness = struct_sdl->param.brightness_default + 2;
	}

}
