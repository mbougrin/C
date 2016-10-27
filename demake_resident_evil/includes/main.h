/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 16:34:57 by mbougrin          #+#    #+#             */
/*   Updated: 2014/11/02 03:11:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include "../libft/includes/libft.h"
# include "menu.h"
# include "free.h"

# define NAME "Resident Evil Demake"
# define POS_X 0
# define POS_Y 0
# define POS_WIDTH 800
# define POS_HEIGHT 600
# define SDL_WIN_FLAGS SDL_WINDOW_SHOWN
# define SDL_INIT_FLAGS SDL_INIT_EVERYTHING

typedef struct			s_option
{
	char			name[64];
	int			w;
	int			h;
	int			x;
	int			y;
	int			r;
	int			g;
	int			b;
	void			*ptr_function;
	struct s_option		*prev;
	struct s_option		*next;
	struct s_option		*down;
	struct s_option		*up;
}				t_option;

typedef struct		s_param
{
	int		quality_text;
	unsigned int	width;
	unsigned int	height;
	int		keyboard;
	int		fullscreen;
	float		brightness;
	float		brightness_default;
	int		quit;
	t_option	*cursor;
	int		nb_cursor;
}			t_param;

typedef	struct		s_sdl
{
	SDL_Window	*win_sdl;
	SDL_Event	event;
	SDL_Color 	color;
	SDL_Rect	pos;
	SDL_Surface	*sprite;
	SDL_Texture	*texture;
	SDL_Joystick	*joy;
	SDL_Thread	*thread[128];
	t_param		param;
}			t_sdl;

void		ft_init_sdl(void);
void		ft_create_win_sdl(SDL_Window** win_sdl, int w, int h);
void		ft_init_ttf(void);
void		ft_init_renderer(SDL_Window *win_sdl);
void		ft_init_font(const char *font, int size);
TTF_Font	*ft_getfont(void);
SDL_Renderer	*ft_getrenderer(void);
void		ft_write_tty(const char* str, SDL_Rect *pos, SDL_Color *color);
t_sdl		*ft_getstruct_sdl(void);
void		ft_init_struct_sdl(void);
void		ft_init_sdl_rect(int w, int h, int x, int y);
void		ft_init_sdl_color(int r, int g, int b);
void		ft_free_struct_sdl(void);
void		ft_load_sprite(const char *sprite);
void		ft_draw_background(int r, int g, int b, int a);
void		ft_draw_rect(void);
void		ft_draw_point(int x, int y);
void		ft_draw_line(int x1, int y1, int x2, int y2);
void		ft_free(void);
void		ft_init_option(void);
void		ft_check_main_option(void);
void		ft_check_event_option(void);
void		ft_load_image(const char *str);

#endif
