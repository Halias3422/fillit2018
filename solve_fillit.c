/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:22:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 14:26:07 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_remove_last_piece(t_fillist *list, char **res, int *coord)
{
	int			i;
	int			first;
	int			y;
	int			x;
	char		letter;

	letter = 'A' + list->tetro_nb;
	i = 0;
	y = 0;
	first = 0;
	while (res[y])
	{
		x = 0;
		while (res[y][x])
		{
			if (res[y][x] == letter && first++ == 0)
			{
				coord[1] = y;
				coord[0] = x;
			}
			if (res[y][x] == letter)
				res[y][x] = '.';
			x++;
		}
		y++;
	}
	return (res);
}

/*
 ** coord[2] = coordinates of res tab:
 ** coord[1] = y
 ** coord[0] = x
 */

void			print_tetro(t_fillist *tetro)
{
	int i;

	i = 0;
	while (tetro->tetros[i])
	{
		ft_putstr(tetro->tetros[i]);
		ft_putstr(" = print list tetro\n");
		i++;
	}
}

char			**ft_initiate_fill_res_tab(t_fillist *list, char **res)
{
	int			coord[2];
	int			i = 0;
	t_fillist	*head;
	t_fillist	*tmp;
	char		tetro_num;

	head = list;
	tmp = head;
	coord[1] = 0;
	while (res[coord[1]] && list != NULL)
	{
		coord[0] = 0;
		while (res[coord[1]][coord[0]] && list != NULL)
		{
			if (res[coord[1]][coord[0]] == '.')
			{
				if ((ft_init_verif(res, list, coord[1], coord[0])) == 1)
				{
					coord[0] = 0;
					coord[1] = 0;
					i = 0;
					while (res[i])
					{
						printf("res[%d] = %s\n", i, res[i]);
						i++;
					}
					list = list->next;
					tetro_num = list->tetro_nb - 1;
				}
			}
			coord[0]++;
		}
		coord[1]++;
	}
	if (coord[1] == (int)ft_strlen(res[coord[1] - 1]))
	{
		while (tmp->tetro_nb <= tetro_num)
			tmp = tmp->next;
		list = tmp;
		res = ft_remove_last_piece(list, res, &coord[2]);
	}
	return (res);
}
