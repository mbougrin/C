/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_sounds_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaitsev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 06:53:15 by zaitsev           #+#    #+#             */
/*   Updated: 2014/11/02 02:52:48 by zaitsev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_audio_menu_call(void *data, Uint8 *stream, unsigned int len)
{
	t_sound_menu		*sound_menu;

	sound_menu = ft_getsound_menu();
	(void)data;
//	printf("%p\n", stream);
//	printf("%d\n", len);
//	printf("%d\n", sound_menu->audio_len);
	if (sound_menu->audio_len == 0)
	{
		sound_menu->audio_pos = sound_menu->audio_pos_begin;
		sound_menu->audio_len = sound_menu->audio_len_begin;
	}
	if (len > sound_menu->audio_len)
		len = sound_menu->audio_len;
	SDL_MixAudio(stream, sound_menu->audio_pos, len, SDL_MIX_MAXVOLUME);
	sound_menu->audio_pos += len;
	sound_menu->audio_len -= len;
}

int		ft_play_sound_menu(void *ptr)
{
	t_sound_menu	*sound_menu;

	sound_menu = ft_getsound_menu();
	(void)ptr;
	if (SDL_OpenAudio(&sound_menu->wav_spec, NULL) < 0)
	{
		ft_putstr_fd("Couldn't open audio: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		ft_free();
		exit(-1);
	}
	SDL_PauseAudio(0);
	while (sound_menu->audio_len > 0);
	SDL_PauseAudio(1);
	return (0);
}
