/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 15:59:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:09:46 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

t_option	*g_lst_option;

t_option	*ft_getlst_option(void)
{
	return (g_lst_option);
}

void		ft_init_option(void)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.quality_text = 2;
	struct_sdl->param.width = POS_WIDTH;
	struct_sdl->param.height = POS_HEIGHT;
	struct_sdl->param.keyboard = 1;
	struct_sdl->param.fullscreen = 0;
	struct_sdl->param.brightness = SDL_GetWindowBrightness(struct_sdl->win_sdl);
	struct_sdl->param.brightness_default = SDL_GetWindowBrightness(struct_sdl->win_sdl);
}

void		ft_create_lst_option(void)
{
	t_option	*lst_text = ft_lst_add(2); 
	t_option	*lst_win = ft_lst_add(3); 
	t_option	*lst_keyboard = ft_lst_add(2); 
	t_option	*lst_fullscreen = ft_lst_add(2); 
	t_option	*lst_brightness = ft_lst_add(3); 

	ft_init_text(&lst_text);
	ft_init_win(&lst_win);
	ft_init_keyboard(&lst_keyboard);
	ft_init_fullscreen(&lst_fullscreen);
	ft_init_brightness(&lst_brightness);
	g_lst_option = lst_text;
	ft_lst_init_up(lst_text, lst_brightness, lst_win);	
	ft_lst_init_up(lst_win, lst_text, lst_keyboard);	
	ft_lst_init_up(lst_keyboard, lst_win, lst_fullscreen);	
	ft_lst_init_up(lst_fullscreen, lst_keyboard, lst_brightness);	
	ft_lst_init_up(lst_brightness, lst_fullscreen, lst_text);	
}

void		ft_free_option(void)
{
	t_option	*lst;
	t_option	*tmp;

	lst = ft_getlst_option();
	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}
