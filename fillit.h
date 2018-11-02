/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:47:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:06:09 by vde-sain    ###    #+. /#+    ###.fr     */
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

# define BUFF_SIZE 5

typedef struct			s_fillist
{
	int					tetro_nb;
	char				**tetros;
	struct s_fillist	*next;
}						t_fillist;

typedef struct			s_gnlist
{
	int					fd;
	char				*str;
	struct s_gnlist		*next;
}						t_gnlist;

char					*ft_read_and_store_file(int fd);
int						get_next_line(const int fd, char **line);

#endif
