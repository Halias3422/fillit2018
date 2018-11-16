/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 15:11:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 16:15:33 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**coord[2] = coordinates of res tab:
**coord[1] = y
**coord[0] = x
*/

static int			*ft_rewind(int *coord, t_fillist *tmp, t_fillist *link
					, char **res)
{
	t_fillist		*head;
	int				len;

	len = (int)ft_strlen(res[*coord]);
	head = tmp;
	if (coord[1] == len)
	{
		link = ft_go_back_list(link, tmp);
		if ((link->next != NULL && ft_check_before_remove(res, link) == 1))
			coord = ft_remove_last_piece(link, res, coord, len);
	}
	return (coord);
}

static t_fillist		*ft_res_filling_error(t_fillist *link, char ***res, int *coord
					, t_fillist *tmp)
{
	if (link != NULL && link->tetro_nb == 0 && ft_check_before_remove(*res, link) == 0)
	{
		*res = ft_malloc_tab(tmp, *res, ++coord[2]);
		coord = ft_fill_coord(coord);
	}
	else if (link != NULL)
	{
		coord = ft_rewind(coord, tmp, link, *res);
		link = ft_go_back_list(link, tmp);
	}
	return (link);
}

char				**ft_fill_res_tab(t_fillist *list, char **res, int *coord,
					t_fillist *link)
{
	t_fillist		*tmp;
	
	if (coord[0] == 0 && coord[1] == 0)
		tmp = list;
	while (link != NULL)
	{
		while (res[coord[1]] && link != NULL)
		{
			while (res[coord[1]][coord[0]] && link != NULL)
			{
				if ((res[coord[1]][coord[0]] == '.') &&
						(ft_init_verif(res, link, coord[1], coord[0])) == 1)
				{
					coord[0] = -1;
					coord[1] = 0;
					link = link->next;
				}
				coord[0]++;
			}
			coord[0] = 0;
			coord[1]++;
		}
		link = ft_res_filling_error(link, &res, coord, tmp);
	}
	return (res);
}
