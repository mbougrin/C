/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:06:13 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:06:39 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		*ft_return_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.nb_cursor == 1)
		return (ft_modify_quality);
	else if (struct_sdl->param.nb_cursor == 2)
		return (ft_modify_sizescreen);
	else if (struct_sdl->param.nb_cursor == 3)
		return (ft_modify_keyboard);
	else if (struct_sdl->param.nb_cursor == 4)
		return (ft_modify_fullscreen);
	else if (struct_sdl->param.nb_cursor == 5)
		return (ft_modify_brightness);
	return (NULL);
}

void		ft_up_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.cursor->r = 255;
	struct_sdl->param.cursor->g = 255;
	struct_sdl->param.cursor = struct_sdl->param.cursor->up;
	if (struct_sdl->param.nb_cursor == 1)
		struct_sdl->param.nb_cursor = 5;
	else
		struct_sdl->param.nb_cursor--;
	ft_sort_default();

}

void		ft_down_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.cursor->r = 255;
	struct_sdl->param.cursor->g = 255;
	struct_sdl->param.cursor = struct_sdl->param.cursor->down;
	if (struct_sdl->param.nb_cursor == 5)
		struct_sdl->param.nb_cursor = 1;
	else
		struct_sdl->param.nb_cursor++;
	ft_sort_default();
}

void		ft_left_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.cursor->r = 255;
	struct_sdl->param.cursor->g = 255;
	struct_sdl->param.cursor = struct_sdl->param.cursor->prev;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;
}

void		ft_right_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.cursor->r = 255;
	struct_sdl->param.cursor->g = 255;
	struct_sdl->param.cursor = struct_sdl->param.cursor->next;
	struct_sdl->param.cursor->r = 0;
	struct_sdl->param.cursor->g = 0;

}
