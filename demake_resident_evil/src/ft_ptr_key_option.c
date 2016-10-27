/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_key_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:06:57 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:56:31 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

int		ft_center_text_option(int nb, int div)
{
	t_sdl		*struct_sdl;
	int		res;

	struct_sdl = ft_getstruct_sdl();
	res = 0;
	res = struct_sdl->param.height - nb;
	res = res / div;
	return (res);
}

int		ft_center_option(int nb, int div)
{
	t_sdl		*struct_sdl;
	int		res;

	struct_sdl = ft_getstruct_sdl();
	res = 0;
	res = struct_sdl->param.width - nb;
	res = res / div;
	return (res);
}

void		*ft_key_option_fr(int sym)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (sym == SDLK_ESCAPE)
		struct_sdl->param.quit = 0;
	else if (sym == SDLK_RETURN)
		return (ft_return_option());
//	else if (sym == SDLK_BACKSPACE)
//		struct_sdl->param.quit = 0;
	else if (sym == SDLK_UP || struct_sdl->event.key.keysym.sym == SDLK_z)
		ft_up_option();
	else if (sym == SDLK_DOWN || struct_sdl->event.key.keysym.sym == SDLK_s)
		ft_down_option();
	else if (sym == SDLK_LEFT || struct_sdl->event.key.keysym.sym == SDLK_q)
		ft_left_option();
	else if (sym == SDLK_RIGHT || struct_sdl->event.key.keysym.sym == SDLK_d)
		ft_right_option();
	return (NULL);
}

void		*ft_key_option(int sym)
{
	t_sdl	*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	if (sym == SDLK_ESCAPE)
		struct_sdl->param.quit = 0;
	else if (sym == SDLK_RETURN)
		return (ft_return_option());
//	else if (sym == SDLK_BACKSPACE)
//		struct_sdl->param.quit = 0;
	else if (sym == SDLK_UP || struct_sdl->event.key.keysym.sym == SDLK_w)
		ft_up_option();
	else if (sym == SDLK_DOWN || struct_sdl->event.key.keysym.sym == SDLK_s)
		ft_down_option();
	else if (sym == SDLK_LEFT || struct_sdl->event.key.keysym.sym == SDLK_a)
		ft_left_option();
	else if (sym == SDLK_RIGHT || struct_sdl->event.key.keysym.sym == SDLK_d)
		ft_right_option();
	return (NULL);
}
