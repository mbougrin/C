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

NAME = logAtWork 
CC = gcc
RM = rm -f
LIB = libft/libft.a -lncurses
INC = -I includes -I libft/includes
CFLAGS = -Wall -Wextra -Werror
DIRSRC = src/
REPO = conf
GIT = http://github.com/mbougrin/$(REPO)
OBJ = 	$(SRC:.c=.o)
SRC = 	$(DIRSRC)main.c \
		$(DIRSRC)ncurse.c \
	   	$(DIRSRC)printNcurse.c \
	   	$(DIRSRC)keyNcurse.c \
	   	$(DIRSRC)lst.c \
	   	$(DIRSRC)lstInfo.c \
	   	$(DIRSRC)save.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(INC)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

init: script
	@git clone $(GIT) && mkdir $(REPO)/logAtWork
	@mkdir tmp data

script:
	@echo "cp -r tmp $(REPO)/logAtWork && cp -r data $(REPO)/logAtWork" > script.sh
	@echo "cd $(REPO)" >> script.sh
	@echo "git add logAtWork && git commit -m 'add $(REPO)' && git push" >> script.sh
	@echo "cd .." >> script.sh

reset:
	@rm -rf $(REPO)
	@rm script.sh
	@rm -rf tmp data

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
