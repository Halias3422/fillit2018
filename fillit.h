/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:47:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 13:05:49 by vde-sain    ###    #+. /#+    ###.fr     */
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
# include "libft/includes/libft.h"

# include <stdio.h>

typedef struct			s_fillist
{
	int					tetro_nb;
	char				**tetros;
	struct s_fillist	*next;
}						t_fillist;

char					*ft_read_and_store_file(int fd);
int						get_next_line(const int fd, char **line);
t_fillist				*ft_fill_list(char *f_cont, t_fillist *list);
char					**ft_create_res_tab(t_fillist *list);
char					**ft_size_tab(t_fillist *list, char **res, int tb_size);
char					**ft_initiate_fill_res_tab(t_fillist *list, char **res);
int						ft_init_verif(char **res, t_fillist *list, int ver,
						int hor);

#endif
