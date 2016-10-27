# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
##   Updated: 2014/11/02 03:11:35 by mbougrin         ###   ########.fr       ##
#                                                                              #
# **************************************************************************** #

NAME = Resident_Evil_Demake 
CC = gcc
SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -I /usr/includes/SDL2/
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC = 	$(DIRSRC)main.c \
	$(DIRSRC)ft_init_sdl.c \
	$(DIRSRC)ft_init_lst_menu.c \
	$(DIRSRC)ft_key_a.c \
	$(DIRSRC)ft_check_event_menu.c \
	$(DIRSRC)ft_sound_menu.c \
	$(DIRSRC)ft_play_sounds_menu.c \
	$(DIRSRC)ft_display_menu.c \
	$(DIRSRC)ft_free_a.c \
	$(DIRSRC)ft_ptr_key_menu.c \
	$(DIRSRC)ft_init_renderer.c \
	$(DIRSRC)ft_init_font.c \
	$(DIRSRC)ft_init_tty.c \
	$(DIRSRC)ft_init_struct_sdl.c \
	$(DIRSRC)ft_init_option.c \
	$(DIRSRC)ft_load_sprite.c \
	$(DIRSRC)ft_load_image.c \
	$(DIRSRC)ft_lst_option.c \
	$(DIRSRC)ft_diver_option.c \
	$(DIRSRC)ft_init_lst_option.c \
	$(DIRSRC)ft_check_first_option.c \
	$(DIRSRC)ft_modify_option.c \
	$(DIRSRC)ft_key_option.c \
	$(DIRSRC)ft_ptr_key_option.c \
	$(DIRSRC)ft_init_event_option.c \
	$(DIRSRC)ft_draw_sdl.c 
	

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(LIB) $(SDL)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
