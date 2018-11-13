/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 15:11:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:19:49 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
 * **coord[2] = coordinates of res tab:
 * **coord[1] = y
 * **coord[0] = x
 * */

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
				coord[0] = x + 1;
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
static char		**ft_rewind(int *coord, t_fillist *tmp, t_fillist *link
		, char **res)
{
	printf("len = %d\n", (int)ft_strlen(res[*coord]) - 1);
	if (coord[1] == (int)ft_strlen(res[*coord]))
	{
		printf("link->tetro_nb = %d\n", link->tetro_nb);
		while (tmp->tetro_nb < link->tetro_nb - 1)
			tmp = tmp->next;
		printf("tmp->tetro_nb = %d\n", tmp->tetro_nb);
		link = tmp;
		coord = ft_remove_last_piece(link, res, coord);
		int j = 0;
		while (res[j])
		{
			printf("res[j] = %s\n", res[j]);
			j++;
		}
/*		if (coord[1] == (int)ft_strlen(res[coord[1] - 1]) &&
			coord[0] == (int)ft_strlen(res[coord[0] - 1]) && link->tetro_nb == 0)
		{
			ft_putstr("le jambon c'est bon");
			res = ft_malloc_tab(link, res, 1);
		}*/
		ft_fill_res_tab(link, res, coord);
	}
	return (res);
}


char			**ft_fill_res_tab(t_fillist *list, char **res, int *coord)
{
	t_fillist	*link;
	t_fillist	*tmp;

	if (coord[0] == 0 && coord[1] == 0)
		tmp = list;
	link = list;
	printf("tetro_nb = %d\n", link->tetro_nb);
	while (res[coord[1]] && link != NULL)
	{
		while (res[coord[1]][coord[0]] && link != NULL)
		{
			if ((res[coord[1]][coord[0]] == '.') && 
					(ft_init_verif(res, link, coord[1], coord[0])) == 1)
			{
				coord[0] = 0;
				coord[1] = 0;
				link = link->next;
				int j = 0;
				while (res[j])
				{
					printf("	BEFOREres[j] = %s\n", res[j]);
					j++;
				}
			}
			coord[0]++;
		}
		coord[0] = 0;
		coord[1]++;
	}
	printf("coord[0] = %d coord[1] = %d\n", coord[0], coord[1]);
	res = ft_rewind(coord, tmp, link, res);
	return (res);
}

