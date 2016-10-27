/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 14:46:58 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/02 02:44:36 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_free_sound_menu(void)
{
	t_sound_menu		*sound_menu;

	sound_menu = ft_getsound_menu();
	SDL_FreeWAV(sound_menu->audio_pos_begin);
}

void		ft_free_struct_sdl(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	free(struct_sdl);
	struct_sdl = NULL;
}

void		ft_free(void)
{
	ft_free_struct_sdl();
	ft_free_lst_menu();
	ft_free_sound_menu();
	TTF_CloseFont(ft_getfont());
	TTF_Quit();
	SDL_CloseAudio();
	SDL_Quit();
	exit(0);
}

void		ft_free_lst_menu(void)
{
	t_menu		*lst;
	t_menu		*next;

	lst = ft_getlst_menu();
	next = lst->next;
	while (next)
	{
		free(lst);
		lst = NULL;
		lst = next;
		next = lst->next;
	}
	free(lst);
	lst = NULL;
}
