/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 21:30:05 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/02 02:57:30 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		main(void)
{
	ft_init_struct_sdl();
	ft_init_option();
	ft_init_lst_menu();
	ft_init_sound_menu();
	ft_draw_background(0, 0, 0, 0);
	ft_check_event_menu();    
	ft_free();
	return (0);
}
