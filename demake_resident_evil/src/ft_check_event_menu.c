/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_event_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 14:40:31 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/02 02:57:55 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_check_event_menu_type(void (*ptr_function)(void))
{
	t_sdl			*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (struct_sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
		struct_sdl->param.quit = 0;
	if (struct_sdl->event.window.event == 1)
	{
		ptr_function = ft_keymenu(struct_sdl->event.key.keysym.sym);
		if (ptr_function)
			(*ptr_function)();
	}
}

void		ft_check_event_menu(void)
{
	t_sdl			*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.quit = 1;
	if (!struct_sdl->thread[0])
		struct_sdl->thread[0] = SDL_CreateThread
			(ft_play_sound_menu, "sound_menu", NULL);
	ft_display_menu();
	while (struct_sdl->param.quit)
	{
		if (SDL_PollEvent(&struct_sdl->event) == 1)
		{
			if (struct_sdl->event.type)
				ft_check_event_menu_type(NULL);
		}
	}
}
