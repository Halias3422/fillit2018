/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:22:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:59:38 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_remove_last_piece(t_fillist *list, char **res, int *coord)
{
	int			first;
	int			y;
	int			x;

	y = 0;
	first = 0;
	while (res[y])
	{
		x = 0;
		while (res[y][x])
		{
			if (res[y][x] && res[y][x] == 'A' + list->tetro_nb && first++ == 0)
			{
				coord[1] = y;
				coord[0] = x;
			}
			if (res[y][x] && res[y][x] == 'A' + list->tetro_nb)
			{
				res[y][x] = '.';
			}
			x++;
		}
		y++;
	}
	return (coord);
}

/*
 ** coord[3] = coordinates of res tab and position in list:
 ** coord[2] = tetro_nb;
 ** coord[1] = y
 ** coord[0] = x
 */

int				*ft_move_through_res(int *coord, t_fillist *link, char **res)
{
	while (link != NULL && res[coord[1]])
	{
		while (res[coord[1]][coord[0]] && link != NULL)
		{
			if (res[coord[1]][coord[0]] == '.')
			{
				if ((ft_init_verif(res, link, coord[1], coord[0])) == 1)
				{
					coord[0] = -1;
					coord[1] = 0;
					link = link->next;
				}
			}
			coord[0]++;
		}
		coord[0] = 0;
		coord[1]++;
		coord[2] = link->tetro_nb;
		ft_putstr("PROUT");
	}
	printf("coord[0] = %d, coord[1] = %d, coord[2] = %d\n", coord[0], coord[1], coord[2]);
	return (coord);
}

char			**ft_fill_res_tab(t_fillist *list, char **res, int y, int x)
{
	int			*coord;
	t_fillist	*link;
	t_fillist	*tmp;

	if (!(coord = (int*)malloc(sizeof(int) * 3)))
		return (NULL);
	tmp = list;
	link = list;
	coord[0] = x;
	coord[1] = y;
//	while (res[coord[1]] && link != NULL)
//	{
		coord = ft_move_through_res(coord, link, res);
/*		while (res[coord[1]][coord[0]] && link != NULL)
		{
			if (res[coord[1]][coord[0]] == '.')
			{
				if ((ft_init_verif(res, link, coord[1], coord[0])) == 1)
				{
					coord[0] = 0;
					coord[1] = 0;
					link = link->next;
				}
			}
			coord[0]++;
		}
		coord[0] = 0;
		coord[1]++;*/
///	}
		//printf("APREScoord[0] = %d, coord[1] = %d, coord[2] = %d\n", coord[0], coord[1], coord[2]);
		while (link->tetro_nb <= coord[2])
		{
			link = link->next;
		}
	if (coord[1] == (int)ft_strlen(res[coord[1] - 1]))
	{
		while (tmp->tetro_nb < link->tetro_nb - 1)
			tmp = tmp->next;
		link = tmp;
		coord = ft_remove_last_piece(link, res, coord);
		ft_fill_res_tab(link, res, coord[1], coord[0] + 1);
	}
	return (res);
}
