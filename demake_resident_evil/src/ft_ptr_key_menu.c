/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_event_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 14:38:03 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/02 02:55:06 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_return_main_menu(void)
{
	t_menu		*lst;
	void		(*ptr_function)(void);

	lst = ft_getlst_menu();
	ptr_function = NULL;
	while (lst->r != 0)
		lst = lst->next;
	ptr_function = ft_keymenu_check_return(&lst);
	if (ptr_function)
		(*ptr_function)();
}

void		ft_escape_main_menu(void)
{
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	struct_sdl->param.quit = 0;
}

void		ft_up_main_menu(void)
{
	t_menu		*lst;

	lst = ft_getlst_menu();
	while (lst->r != 0)	
		lst = lst->next;
	if ((ft_strcmp(lst->name_pos, "new game")) == 0)
	{
		lst->g = 255;
		lst->r = 255;
/* Gestion des colisions du menu */
		while ((ft_strcmp(lst->name_pos, "quit")) != 0)
			lst = lst->next;
		lst->g = 0;
		lst->r = 0;
	}
	else
	{
		lst->g = 255;
		lst->r = 255;
		lst = lst->prev;
		lst->g = 0;
		lst->r = 0;
	}
	ft_display_menu();
}

void		ft_down_main_menu(void)
{
	t_menu		*lst;

	lst = ft_getlst_menu();
	while (lst->r != 0)	
		lst = lst->next;
	if ((ft_strcmp(lst->name_pos, "quit")) == 0)
	{
		lst->g = 255;
		lst->r = 255;
/* Gestion des colisions du menu */
		while ((ft_strcmp(lst->name_pos, "new game")) != 0)
			lst = lst->prev;
		lst->g = 0;
		lst->r = 0;
	}
	else
	{
		lst->g = 255;
		lst->r = 255;
		lst = lst->next;
		lst->g = 0;
		lst->r = 0;
	}
	ft_display_menu();
}
