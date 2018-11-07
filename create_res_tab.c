/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 14:34:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 15:59:52 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_find_smallest_square(t_fillist *list)
{
	int				i;
	int				j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->tetros[j++])
			i++;
		list = list->next;
	}
	return (i);
}

static char		**fill_tab_points(char **res)
{
	int			i;
	int			j;

	j = 0;
	while (res[j])
	{
		i = 0;
		while(res[j][i])
		{
			res[j][i] = '.';
			printf("TESTres[%d][%d] = %c", j, i, res[j][i]);
		}
		j++;
	}
	return (res);
}

char			**ft_malloc_tab(t_fillist *list, char **res, int tb_size)
{
	int				i;
	int				res_min;
	int				square_size;

	i = 0;
	res_min = ft_find_smallest_square(list);
	square_size = (res_min / 4) + 1;
	if (!(res = (char**)malloc(sizeof(char*) * (square_size + tb_size))))
		return (NULL);
	res[res_min / 4] = NULL;
	while (i < res_min / 4)
	{
		if (!(res[i] = (char*)malloc(sizeof(char) * (square_size + tb_size))))
			return (NULL);
		res[i][res_min / 4] = '\0';
		i++;
	}
	res = fill_tab_points(res);
	return (res);
}

char				**ft_create_res_tab(t_fillist *list)
{
	char			**res;
	int				tab_size;

	res = NULL;
	tab_size = 0;
	res = ft_malloc_tab(list, res, tab_size);
	return (res);
}
