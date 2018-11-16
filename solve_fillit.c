/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 15:11:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 15:51:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**coord[2] = coordinates of res tab:
**coord[1] = y
**coord[0] = x
*/

static int			*ft_remove_last_piece(t_fillist *list, char **res
					, int *coord, int len)
{
	int				first;
	int				y;
	int				x;
	char			tetro_symb;

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

int					*ft_fill_coord(int *coord, int len, int usage)
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

static int			ft_check_before_remove(char **res, t_fillist *list)
{
	int				i;
	int				j;

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

static t_fillist	*ft_go_back_list(t_fillist *link, t_fillist *tmp)
{
	while (tmp->next != NULL && (tmp->next->tetro_nb < link->tetro_nb))
		tmp = tmp->next;
	return (tmp);
}

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

char				**ft_fill_res_tab(t_fillist *list, char **res, int *coord)
{
	t_fillist		*link;
	static t_fillist*tmp;
	
	if (coord[0] == 0 && coord[1] == 0)
		tmp = list;
	link = list;
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
		if (link != NULL && link->tetro_nb == 0 && ft_check_before_remove(res, link) == 0)
		{
			res = ft_malloc_tab(tmp, res, ++coord[2]);
			ft_fill_coord(coord, (int)ft_strlen(res[coord[1]]), 0);
		}
		if (link != NULL)
		{
			coord = ft_rewind(coord, tmp, link, res);
			link = ft_go_back_list(link, tmp);
		}
	}
	return (res);
}
