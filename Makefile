# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/02 14:34:41 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/19 13:51:35 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  read_file.c \
	  fill_list.c \
	  create_res_tab.c \
	  solve_fillit.c \
	  check_tetro_placement.c \
	  help_solve.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/

LIBFT.A = ./libft/libft.a

all: libs $(NAME)

$(NAME): $(OBJ) $(LIBFT.A)
		@$(CC) -o $(NAME) $(OBJ) libft/libft.a
		@echo "\033[1;32mFILLIT				OK"
libs:
		@(cd $(LIBFT) && $(MAKE))

%.o: %.c fillit.h
		@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mCLEAN FILLIT			OK"

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mFCLEAN FILLIT			OK"

re: fclean all

.PHONY : all clean fclean re
