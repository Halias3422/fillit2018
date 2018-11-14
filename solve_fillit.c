/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 15:11:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 15:21:32 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**coord[2] = coordinates of res tab:
**coord[1] = y
**coord[0] = x
*/

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

int				*ft_fill_coord(int *coord, int len, int usage)
{
	if (usage == 0)
	{
		coord[0] = 0;
		coord[1] = 0;
	}
	else if (usage == 1)
	{
		coord[0] = len;
		coord[1] = len;
	}
	return (coord);
}

static int		ft_check_before_remove(char **res)
{
	int			i;
	int			j;

	j = 0;
	while (res[j])
	{
		i = 0;
		while (res[j][i])
		{
			if (res[j][i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static char		**ft_rewind(int *coord, t_fillist *tmp, t_fillist *link
				, char **res)
{
	t_fillist	*head;
	int			len;

	len = (int)ft_strlen(res[*coord]);
	head = tmp;
	if (coord[1] == len)
	{
		if (tmp->next != NULL)
		{
		while (tmp->next->tetro_nb < link->tetro_nb)
			tmp = tmp->next;
		link = tmp;
		}
		if ((link->next != NULL && ft_check_before_remove(res) == 1))
			coord = ft_remove_last_piece(link, res, coord);
		else
			ft_fill_coord(coord, len, 1);
		if (coord[1] >= len && coord[0] >= len && link->tetro_nb == 0)
		{
			res = ft_malloc_tab(head, res, ++coord[2]);
			link = head;
			ft_fill_coord(coord, len, 0);
		}
		res = ft_fill_res_tab(link, res, coord);
	}
	return (res);
}

char			**ft_fill_res_tab(t_fillist *list, char **res, int *coord)
{
	t_fillist	*link;
static t_fillist*tmp;

	if (coord[0] == 0 && coord[1] == 0)
		tmp = list;
	link = list;
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
	res = ft_rewind(coord, tmp, link, res);
	return (res);
}
