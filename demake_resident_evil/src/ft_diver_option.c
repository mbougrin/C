/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diver_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:03:04 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:03:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		ft_change_sizescreen(unsigned int w, unsigned int h)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.height = h;
	struct_sdl->param.width = w;
	SDL_DestroyWindow(struct_sdl->win_sdl);
	SDL_DestroyRenderer(ft_getrenderer());
	ft_create_win_sdl(&struct_sdl->win_sdl, w, h);
	ft_init_renderer(struct_sdl->win_sdl);
	ft_modify_lst_option();
}

void		ft_print_text_option(void)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	ft_init_sdl_rect(150, 80, struct_sdl->param.width / 2 - 80, 10);
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Option", &struct_sdl->pos, &struct_sdl->color);
	ft_init_sdl_rect(100, 50, 10, 100 +ft_center_text_option(100, 11));
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Quality", &struct_sdl->pos, &struct_sdl->color);
	ft_init_sdl_rect(150, 50, 10, 100 + (ft_center_text_option(100, 11) * 3));
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Screen Size", &struct_sdl->pos, &struct_sdl->color);
	ft_init_sdl_rect(100, 50, 10, 100 + (ft_center_text_option(100, 11) * 5));
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Keyboard", &struct_sdl->pos, &struct_sdl->color);
	ft_init_sdl_rect(150, 50, 10, 100 + (ft_center_text_option(100, 11) * 7));
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Fullscreen", &struct_sdl->pos, &struct_sdl->color);
	ft_init_sdl_rect(150, 50, 10, 100 + (ft_center_text_option(100, 11) * 9));
	ft_init_sdl_color(250, 240, 197);
	ft_write_tty("Brightness", &struct_sdl->pos, &struct_sdl->color);
}

void		ft_modify_lst_option(void)
{
	t_option	*lst;

	lst = ft_getlst_option();
	ft_init_text(&lst);
	ft_init_win(&lst->down);
	ft_init_keyboard(&lst->down->down);
	ft_init_fullscreen(&lst->up->up);
	ft_init_brightness(&lst->up);
}	

void		ft_sort_default(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->param.nb_cursor == 1)
		ft_check_text_option();
	else if (struct_sdl->param.nb_cursor == 2)
		ft_check_size_option();
	else if (struct_sdl->param.nb_cursor == 3)
		ft_check_keyboard_option();
	else if (struct_sdl->param.nb_cursor == 4)
		ft_check_fullscreen_option();
	else if (struct_sdl->param.nb_cursor == 5)
		ft_check_brightness_option();
}
