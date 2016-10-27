/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 16:23:12 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/01 22:39:17 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# define SOUND_PATH "sound/test.wav"

typedef struct			s_menu
{
	char			*name_pos;
	int			w;
	int			h;
	int			x;
	int			y;
	int			r;
	int			g;
	int			b;
	struct s_menu		*prev;
	struct s_menu		*next;
}				t_menu;

typedef struct			s_sound_menu
{
	Uint8			*audio_pos;
	Uint8			*audio_pos_begin;
	Uint32			audio_len;
	Uint32			audio_len_begin;
	SDL_AudioSpec		wav_spec;
}				t_sound_menu;

void		ft_init_lst_menu(void);
void		ft_init_lst(char *str);
void		ft_init_color_lst(int r, int g, int b);
void		ft_init_pos_lst(int w, int h, int x, int y);
void		ft_up_main_menu(void);
void		ft_down_main_menu(void);
void		ft_escape_main_menu(void);
t_menu		*ft_getlst_menu(void);
void		ft_display_menu(void);
void		ft_check_event_menu(void);
void		ft_check_event_menu_type(void (*ptr_function)(void));
void		*ft_keymenu(int sym);
int		ft_play_sound_menu(void *ptr);
void		ft_delay(unsigned int frameLimit);
void		ft_init_sound_menu();
void		ft_init_audio_wav(void);
void		ft_init_struct_sound_menu(void);
t_sound_menu	*ft_getsound_menu(void);
void		ft_audio_menu_call(void *data, Uint8 *stream, unsigned int len);
void		ft_return_main_menu(void);
void		*ft_keymenu_check_return(t_menu **lst);
 
#endif
