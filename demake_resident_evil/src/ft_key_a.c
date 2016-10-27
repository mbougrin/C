/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 16:57:53 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/02 02:58:07 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		*ft_keymenu_check_return(t_menu **lst)
{
	if ((ft_strcmp((*lst)->name_pos, "new game")) == 0)
		return (ft_free);
	else if ((ft_strcmp((*lst)->name_pos, "load game")) == 0)
		return (ft_free);
	else if ((ft_strcmp((*lst)->name_pos, "options")) == 0)
		return (ft_check_event_option);	
	else if ((ft_strcmp((*lst)->name_pos, "quit")) == 0)
		return (ft_free);
	return (NULL);
}

void		*ft_keymenu(int sym)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (sym == SDLK_ESCAPE)
		return (ft_escape_main_menu);
	else if (sym == SDLK_RETURN)
		return (ft_return_main_menu);
	else if (sym == SDLK_UP || struct_sdl->event.key.keysym.sym == SDLK_w)
		return (ft_up_main_menu);
	else if (sym == SDLK_DOWN || struct_sdl->event.key.keysym.sym == SDLK_s)
		return (ft_down_main_menu);
	return (NULL);
}
