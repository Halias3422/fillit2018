/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 14:34:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 18:18:04 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_find_smallest_square(t_fillist *list)
{
	int				i;
	int				original_i;
	int				j;
	int				square_verif;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->tetros[j++])
			i++;
		list = list->next;
	}
	square_verif = i / 4;
	original_i = i;
	while (square_verif * square_verif < original_i)
	{
		i++;
		square_verif = i / 4;
	}
	return (i);
}

char			**ft_malloc_tab(t_fillist *list, char **res, int tb_size)
{
	int				i;
	int				j;
	int				res_min;
	int				square_size;

	j = 0;
	printf("res_min = %d\n", res_min = ft_find_smallest_square(list));
	square_size = (res_min / 4) + 1;
	if (!(res = (char**)malloc(sizeof(char*) * (square_size + tb_size))))
		return (NULL);
	while (j < square_size - 1)
	{
		i = 0;
		if (!(res[j] = (char*)malloc(sizeof(char) * (square_size + tb_size))))
			return (NULL);
		while (i < square_size - 1)
			res[j][i++] = '.';
		res[j][i] = '\0';
		j++;
	}
	res[j] = NULL;
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
