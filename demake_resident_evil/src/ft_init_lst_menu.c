/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/27 17:58:54 by zaitsev           #+#    #+#             */
/*   Updated: 2014/10/31 06:02:07 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_menu		*g_lst_menu;
t_menu		*pos_prev;
t_menu		*head;

t_menu		*ft_getlst_menu(void)
{
	return (g_lst_menu);	
}

void		ft_init_pos_lst(int w, int h, int x, int y)
{
	g_lst_menu->w = w;
	g_lst_menu->h = h;
	g_lst_menu->x = x;
	g_lst_menu->y = y;
}

void		ft_init_color_lst(int r, int g, int b)
{
	g_lst_menu->r = r;
	g_lst_menu->g = g;
	g_lst_menu->b = b;
}

void		ft_init_lst(char *str)
{
	if (!g_lst_menu)
	{
		g_lst_menu = (t_menu *)malloc(sizeof(t_menu));
		g_lst_menu->prev = NULL;
		g_lst_menu->next = NULL;
	}
	else
	{
		g_lst_menu->next = (t_menu *)malloc(sizeof(t_menu));
		pos_prev = g_lst_menu;
		g_lst_menu = g_lst_menu->next;
		g_lst_menu->prev = pos_prev;
		g_lst_menu->next = NULL;
	}		
	g_lst_menu->name_pos = str;
}

void		ft_init_lst_menu(void)
{
	g_lst_menu = NULL;
	pos_prev = NULL;
	ft_init_lst(NAME);
	ft_init_pos_lst(680, 250, POS_WIDTH / 2 - 335, POS_HEIGHT / 2 - 330);
	ft_init_color_lst(255, 0, 0);
	head = g_lst_menu;
	ft_init_lst("new game");
	ft_init_pos_lst(140, 105, POS_WIDTH / 2 - 65, POS_HEIGHT / 2 + 30);
	ft_init_color_lst(0, 0, 255);
	ft_init_lst("load game");
	ft_init_pos_lst(140, 105, POS_WIDTH / 2 - 65, POS_HEIGHT / 2 + 80);
	ft_init_color_lst(255, 255, 255);
	ft_init_lst("options");
	ft_init_pos_lst(140, 105, POS_WIDTH / 2 - 65, POS_HEIGHT / 2 + 130);
	ft_init_color_lst(255, 255, 255);
	ft_init_lst("quit");
	ft_init_pos_lst(140, 95, POS_WIDTH / 2 - 65, POS_HEIGHT / 2 + 185);
	ft_init_color_lst(255, 255, 255);
	g_lst_menu = head;
}
