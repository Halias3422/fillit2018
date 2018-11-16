/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   help_solve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:53:48 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 16:01:54 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				*ft_remove_last_piece(t_fillist *list, char **res
		, int *coord, int len)
{
	int			first;
	int			y;
	int			x;
	char		tetro_symb;

	tetro_symb = 'A' + list->tetro_nb;
	y = 0;
	first = 0;
	while (y < len)
	{
		x = 0;
		while (x < len)
		{
			if (x < len && res[y][x] == tetro_symb && first++ == 0)
			{
				coord[1] = y;
				coord[0] = x + 1;
			}
			if (x < len && res[y][x] == tetro_symb)
			{
				res[y][x] = '.';
			}
			x++;
		}
		y++;
	}
	return (coord);
}

int				*ft_fill_coord(int *coord)
{
	coord[0] = 0;
	coord[1] = 0;
	return (coord);
}

int				ft_check_before_remove(char **res, t_fillist *list)
{
	int			i;
	int			j;

	j = 0;
	while (res[j])
	{
		i = 0;
		while (res[j][i])
		{
			if (res[j][i] == 'A' + list->tetro_nb)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

t_fillist		*ft_go_back_list(t_fillist *link, t_fillist *tmp)
{
	while (tmp->next != NULL && (tmp->next->tetro_nb < link->tetro_nb))
		tmp = tmp->next;
	return (tmp);
}
