/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 03:49:38 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/01 22:11:24 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

void		ft_check_event_option(void);

t_option	*ft_getlst_option(void);
void		ft_init_option(void);
void		ft_create_lst_option(void);
void		ft_lst_init_up(t_option *lst, t_option *up, t_option *down);

void		ft_print_option(void);
t_option	*ft_lst_add(int nb);

int		ft_center_text_option(int nb, int div);
int		ft_center_option(int nb, int div);

void		ft_init_text(t_option **lst_new);
void		ft_init_win(t_option **lst_new);
void		ft_init_keyboard(t_option **lst_new);
void		ft_init_fullscreen(t_option **lst_new);
void		ft_init_brightness(t_option **lst_new);

void		ft_print_text_option(void);
void		ft_modify_lst_option(void);

void		*ft_key_option_fr(int sym);
void		ft_check_text_option(void);
void		ft_check_size_option(void);
void		ft_check_keyboard_option(void);
void		ft_check_fullscreen_option(void);
void		ft_check_brightness_option(void);

void		ft_sort_default(void);

void		ft_modify_quality(void);
void		ft_modify_sizescreen(void);
void		ft_change_sizescreen(unsigned int w, unsigned int h);
void		ft_modify_keyboard(void);
void		ft_modify_fullscreen(void);
void		ft_modify_brightness(void);

void		*ft_return_option(void);
void		ft_up_option(void);
void		ft_down_option(void);
void		ft_left_option(void);
void		ft_right_option(void);
void		*ft_key_option(int sym);
void		ft_free_option(void);

#endif
