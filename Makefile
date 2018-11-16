# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/02 14:34:41 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/16 19:10:41 by vde-sain    ###    #+. /#+    ###.fr      #
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

EXEC = $(LIBFT)/libft.a


all: $(NAME) $(EXEC)

$(EXEC):
		@(cd $(LIBFT) && $(MAKE))

$(NAME): $(OBJ) $(EXEC)
		@$(CC) -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c fillit.h
		@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@(cd $(LIBFT) && $(MAKE) $@)

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)

re: fclean all libft

.PHONY : all clean fclean re
