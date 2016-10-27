/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:03:48 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:04:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		ft_init_text(t_option **lst_new)
{
	ft_strcpy((*lst_new)->name, "Low");
	(*lst_new)->w = 80;
	(*lst_new)->h = 50;
	(*lst_new)->x = 150 + ft_center_option(150, 5);
	(*lst_new)->y = ft_center_text_option(100, 11) + 100;
	ft_strcpy((*lst_new)->next->name, "High");
	(*lst_new)->next->w = 80;
	(*lst_new)->next->h = 50;
	(*lst_new)->next->x = 150 + (ft_center_option(150, 5) * 3);
	(*lst_new)->next->y = ft_center_text_option(100, 11) + 100;
}

void		ft_init_win(t_option **lst_new)
{
	ft_strcpy((*lst_new)->name, "800x600");
	(*lst_new)->w = 100;
	(*lst_new)->h = 50;
	(*lst_new)->x = 150 + ft_center_option(150, 7);
	(*lst_new)->y = 100 + (ft_center_text_option(100, 11) * 3);
	ft_strcpy((*lst_new)->next->name, "1280x1024");
	(*lst_new)->next->w = 120;
	(*lst_new)->next->h = 50;
	(*lst_new)->next->x = 150 + (ft_center_option(150, 7) * 3);
	(*lst_new)->next->y = 100 + (ft_center_text_option(100, 11) * 3);
	ft_strcpy((*lst_new)->next->next->name, "1920x1080");
	(*lst_new)->next->next->w = 120;
	(*lst_new)->next->next->h = 50;
	(*lst_new)->next->next->x = 150 + (ft_center_option(150, 7) * 5);
	(*lst_new)->next->next->y = 100 + (ft_center_text_option(100, 11) * 3);
}

void		ft_init_keyboard(t_option **lst_new)
{
	ft_strcpy((*lst_new)->name, "En");
	(*lst_new)->w = 50;
	(*lst_new)->h = 50;
	(*lst_new)->x = 150 + ft_center_option(150, 5);
	(*lst_new)->y = 100 + (ft_center_text_option(100, 11) * 5);
	ft_strcpy((*lst_new)->next->name, "Fr");
	(*lst_new)->next->w = 50;
	(*lst_new)->next->h = 50;
	(*lst_new)->next->x = 150 + (ft_center_option(150, 5) * 3);
	(*lst_new)->next->y = 100 + (ft_center_text_option(100, 11) * 5);
}

void		ft_init_fullscreen(t_option **lst_new)
{
	ft_strcpy((*lst_new)->name, "On");
	(*lst_new)->w = 50;
	(*lst_new)->h = 50;
	(*lst_new)->x = 150 + ft_center_option(150, 5);
	(*lst_new)->y = 100 + (ft_center_text_option(100, 11) * 7);
	ft_strcpy((*lst_new)->next->name, "Off");
	(*lst_new)->next->w = 50;
	(*lst_new)->next->h = 50;
	(*lst_new)->next->x = 150 + (ft_center_option(150, 5) * 3);
	(*lst_new)->next->y = 100 + (ft_center_text_option(100, 11) * 7);
}

void		ft_init_brightness(t_option **lst_new)
{
	ft_strcpy((*lst_new)->name, "0");
	(*lst_new)->w = 50;
	(*lst_new)->h = 50;
	(*lst_new)->x = 150 + ft_center_option(150, 7);
	(*lst_new)->y = 100 + (ft_center_text_option(100, 11) * 9);
	ft_strcpy((*lst_new)->next->name, "1");
	(*lst_new)->next->w = 50;
	(*lst_new)->next->h = 50;
	(*lst_new)->next->x = 150 + (ft_center_option(150, 7) * 3);
	(*lst_new)->next->y = 100 + (ft_center_text_option(100, 11) * 9);
	ft_strcpy((*lst_new)->next->next->name, "2");
	(*lst_new)->next->next->w = 50;
	(*lst_new)->next->next->h = 50;
	(*lst_new)->next->next->x = 150 + (ft_center_option(150, 7) * 5);
	(*lst_new)->next->next->y = 100 + (ft_center_text_option(100, 11) * 9);
}
