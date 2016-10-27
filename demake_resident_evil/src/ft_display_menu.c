/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 14:41:35 by zaitsev           #+#    #+#             */
/*   Updated: 2014/10/30 15:46:10 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();
 
    if (frameLimit < ticks)
        return;
    if (frameLimit > ticks + 16)
        SDL_Delay(16);
    else
        SDL_Delay(frameLimit - ticks);
}

void		ft_display_menu()
{
	t_sdl	*struct_sdl;
	t_menu	*lst_menu;
	unsigned int	framelimit = SDL_GetTicks() + 16;

	struct_sdl = ft_getstruct_sdl();
	lst_menu = ft_getlst_menu();
	SDL_RenderClear(ft_getrenderer());
	while (lst_menu)
	{
		ft_init_sdl_rect(lst_menu->w, lst_menu->h, lst_menu->x, lst_menu->y);
		ft_init_sdl_color(lst_menu->r, lst_menu->g, lst_menu->b);
		ft_write_tty(lst_menu->name_pos, &struct_sdl->pos, &struct_sdl->color);
		lst_menu = lst_menu->next;
	}
	ft_delay(framelimit);
	framelimit = SDL_GetTicks() + 16;
	SDL_RenderPresent(ft_getrenderer());
}
