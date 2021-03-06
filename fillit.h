/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:47:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:39:53 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_fillist
{
	int					tetro_nb;
	char				**tetros;
	char				*form;
	struct s_fillist	*next;
}						t_fillist;

char					*ft_read_and_store_file(int fd);
int						get_next_line(const int fd, char **line);
t_fillist				*ft_fill_list(char *f_cont, t_fillist *list);
char					**ft_create_res_tab(t_fillist *list);
char					**ft_malloc_tab(t_fillist *list, char **res,
						int tb_size, int i);
char					**ft_size_tab(t_fillist *list, char **res, int tb_size);
char					**ft_fill_res_tab(t_fillist *list, char **res,
						int *coord, t_fillist *link);
int						ft_init_verif(char **res, t_fillist *list, int ver,
						int hor);
char					*ft_verif_form(t_fillist *list, char *form);

/*
** HELP SOLVE FILLIT FUNCTIONS
*/

char					*ft_lighten_fill_form(int *co, char *form, char t_symb,
						char **tetros);
int						*ft_remove_last_piece(t_fillist *list, char **res, int
						*cord, int len);
int						*ft_fill_coord(int *coord);
int						ft_check_before_remove(char **res, t_fillist *list);
t_fillist				*ft_go_back_list(t_fillist *link, t_fillist *tmp);

#endif
