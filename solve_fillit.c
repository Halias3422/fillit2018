/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:22:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 18:32:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_calculate_dist(t_fillist *list, int first_pos, int left_pos)
{
	int			hor;
	int			ver;

	hor = 0;
	ver = 0;
	while (list->tetros[ver])
	{
		hor = 0;
		while (list->tetros[ver][hor])
		{
			if (list->tetros[ver][hor] >= 'A' && list->tetros[ver][hor] <= 'Z')
			{
				if (first_pos > 3)
					first_pos = hor;
				else if (hor < left_pos)
					left_pos = hor;
			}
				hor++;
		}
		ver++;
	}
	if (first_pos - left_pos > 0)
		return (first_pos - left_pos);
	else
		return (0);
}

static char		**ft_place_tetro(char **res, t_fillist *list, int ver, int hor)
{
	int			dist;
	int			t_ver;
	int			t_hor;
	int			tetros_symb;

	t_ver = 0;
	tetros_symb = 0;
	printf("dist = %d\n", dist = ft_calculate_dist(list, 4, 4));
	while (tetros_symb < 4 && list->tetros[t_ver])
	{
		t_hor = 0;
		while (list->tetros[t_ver][t_hor])
		{
			ft_putstr("bouh");
			if (list->tetros[t_ver][t_hor] == 'A' + list->tetro_nb)
			{
				if ((hor + dist) <= (int)ft_strlen(list->tetros[t_ver]))
				{
					res[ver][hor + dist] = list->tetros[t_ver][t_hor];
					tetros_symb++;
				}
				else
					return (NULL);
			hor++;
			t_hor++;
			}
		t_ver++;
		ver++;
		}
	}
	return (res);
}

char			**ft_initiate_fill_res_tab(t_fillist *list, char **res)
{
	int			hor;
	int			ver;

	ver = 0;
	while (res[ver] && list != NULL)
	{
		hor = 0;
		while (res[ver][hor])
		{
			if (res[ver][hor] == '.')
			{
				res = ft_place_tetro(res, list, ver, hor);
				list = list->next;
			}
			hor++;
		}
		ver++;
	}
	return (res);
}
