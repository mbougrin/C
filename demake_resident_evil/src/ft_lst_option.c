/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 22:02:07 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:02:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <option.h>

void		ft_lst_init_up(t_option *lst, t_option *up, t_option *down)
{
	t_option	*tmp;

	tmp = lst;
	while (tmp->next != lst)
	{
		tmp->up = up;
		tmp->down = down;
		tmp = tmp->next;
	}
	tmp->up = up;
	tmp->down = down;
}

static void	ft_print_lst(t_option *lst)
{
	t_option	*lst_tmp;
	t_sdl		*struct_sdl;

	struct_sdl = ft_getstruct_sdl();
	lst_tmp = lst;
	while (lst_tmp->next != lst)
	{
		ft_init_sdl_rect(lst_tmp->w, lst_tmp->h, lst_tmp->x, lst_tmp->y);
		ft_init_sdl_color(lst_tmp->r, lst_tmp->g, lst_tmp->b);
		ft_write_tty(lst_tmp->name, &struct_sdl->pos, &struct_sdl->color);
		lst_tmp = lst_tmp->next;
	}
	ft_init_sdl_rect(lst_tmp->w, lst_tmp->h, lst_tmp->x, lst_tmp->y);
	ft_init_sdl_color(lst_tmp->r, lst_tmp->g, lst_tmp->b);
	ft_write_tty(lst_tmp->name, &struct_sdl->pos, &struct_sdl->color);
}

void		ft_print_option(void)
{
	t_option	*opt;
	t_option	*lst;

	lst = ft_getlst_option();
	opt = lst;
	while (lst->down != opt)
	{
		ft_print_lst(lst);
		lst = lst->down;
	}
	ft_print_lst(lst);
}

static t_option	*ft_lst_new(void)
{
	t_option	*new;

	new = (t_option *)malloc(sizeof(t_option));
	if (new == NULL)
		return (NULL);
	else
	{
		new->w = 0;
		new->h = 0;
		new->x = 0;
		new->y = 0;
		new->r = 255;
		new->g = 255;
		new->b = 255;
		new->ptr_function = NULL;
		new->prev = NULL;
		new->next = NULL;
		new->down = NULL;
		new->up = NULL;
	}
	return (new);
}

t_option	*ft_lst_add(int nb)
{
	t_option	*lst;
	t_option	*opt;
	int		i;

	i = 1;
	opt = ft_lst_new();
	lst = opt;
	while (i < nb)
	{
		lst->next = ft_lst_new();
		lst->next->prev = lst;
		lst = lst->next;
		i++;
	}
	lst->next = opt;
	opt->prev = lst;
	return (opt);
}

