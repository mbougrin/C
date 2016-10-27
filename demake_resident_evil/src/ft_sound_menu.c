/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 05:41:30 by zaitsev           #+#    #+#             */
/*   Updated: 2014/10/31 23:45:00 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_sound_menu	*g_sound_menu;

t_sound_menu	*ft_getsound_menu(void)
{
	return (g_sound_menu);
}

void		ft_init_struct_sound_menu(void)
{
	t_sound_menu		*sound_menu;

	sound_menu = ft_getsound_menu();
	SDL_zero(sound_menu->wav_spec);
	sound_menu->wav_spec.callback = (SDL_AudioCallback)ft_audio_menu_call;
	sound_menu->wav_spec.userdata = NULL;
	sound_menu->wav_spec.freq = 44100;
	sound_menu->wav_spec.channels = 2;
	sound_menu->wav_spec.samples = AUDIO_U16MSB;
//	sound_menu->audio_pos += 18000000;
//	sound_menu->audio_len -= 18000000;
	sound_menu->audio_pos_begin = sound_menu->audio_pos;
	sound_menu->audio_len_begin = sound_menu->audio_len;
}

void		ft_init_audio_wav(void)
{
	t_sound_menu	*sound_menu;

	sound_menu = ft_getsound_menu();
	if (!(SDL_LoadWAV(SOUND_PATH, &sound_menu->wav_spec,
		&sound_menu->audio_pos, &sound_menu->audio_len)))
	{
		ft_putstr_fd("Load wav error: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
}

void		ft_init_sound_menu()
{
	g_sound_menu = NULL;
	g_sound_menu = (t_sound_menu *)malloc(sizeof(t_sound_menu));
	g_sound_menu->audio_len = 0;
	g_sound_menu->audio_len_begin = 0;
	g_sound_menu->audio_pos = NULL;
	g_sound_menu->audio_pos_begin = NULL;
	ft_init_audio_wav();
	ft_init_struct_sound_menu();
}
