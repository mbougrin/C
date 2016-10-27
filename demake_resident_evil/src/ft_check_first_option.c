/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_option.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:04:40 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:05:07 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		ft_check_text_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.quality_text == 2)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;
}

void		ft_check_size_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.width == 1280)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	else if (struct_sdl->param.width == 1920)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;

}

void		ft_check_keyboard_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.keyboard == 2)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;
}

void		ft_check_fullscreen_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.fullscreen == 0)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;
}

void		ft_check_brightness_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.brightness == struct_sdl->param.brightness_default + 1)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	else if (struct_sdl->param.brightness == struct_sdl->param.brightness_default + 2)
		struct_sdl->param.cursor = struct_sdl->param.cursor->next->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;
}
