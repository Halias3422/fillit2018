/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:22:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 15:53:42 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_place_tetro(char **res, t_fillist *list, int ver, int hor)
{
	int			t_ver;
	int			t_hor;

	t_ver = 0;
	while (list->tetros[t_ver])
	{
		t_hor = 0;
		while (list->tetros[t_ver][t_hor])
		{
			if (list->tetros[t_ver][t_hor] >= 'A' && list->tetros[t_ver][t_hor] <= 'Z')
				res[ver][hor] = list->tetros[t_ver][t_hor++];
			else
				t_hor++;
		}
		t_ver++;
	}
	return (res);
}

char			**ft_initiate_fill_res_tab(t_fillist *list, char **res)
{
	int			hor;
	int			ver;

	ver = 0;
	while (res[ver])
	{
		hor = 0;
		while (res[ver][hor])
		{
			if (res[ver][hor] != '.')
				hor++;
			else
				res = ft_place_tetro(res, list, ver, hor);
		}
		ver++;
	}
	return (res);
}
