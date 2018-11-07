# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/02 14:34:41 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/07 15:22:47 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  read_file.c \
	  fill_list.c \
	  create_res_tab.c \
	  solve_fillit.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -I. -L./libft -lft $(SRC) -o $@

%.o: %.c fillit.h

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

.SILENT : $(OBJ)
