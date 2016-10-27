/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_event_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:07:39 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:19:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

static void	ft_init_event_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.quit = 1;
	struct_sdl->param.nb_cursor = 1;
	ft_create_lst_option();
	struct_sdl->param.cursor = ft_getlst_option();
	ft_check_text_option();
	SDL_RenderClear(ft_getrenderer());
}

static void	ft_check_event_opt(void)
{
	t_sdl		*struct_sdl;
	void 		(*ptr_function)(void); 

	struct_sdl = ft_getstruct_sdl();
	ptr_function = NULL;
	if (struct_sdl->event.type)
	{
		if (struct_sdl->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			ft_free_option();
			ft_free();
		}
		if ( struct_sdl->event.window.event == 1)
		{
			if (struct_sdl->param.keyboard == 2)
				ptr_function = ft_key_option_fr(struct_sdl \
				->event.key.keysym.sym);
			else
				ptr_function = ft_key_option(struct_sdl \
				->event.key.keysym.sym);
			if (ptr_function)
				(*ptr_function)();
		}
	}
}

void		ft_check_event_option(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	ft_init_event_option();
	while (struct_sdl->param.quit)
	{
		ft_print_text_option();
		ft_print_option();
		if (SDL_PollEvent(&struct_sdl->event))
			ft_check_event_opt();
		SDL_RenderPresent(ft_getrenderer());
		SDL_RenderClear(ft_getrenderer());
	}
	ft_free_option();
	ft_check_event_menu();
}
