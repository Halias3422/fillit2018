/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_res_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 14:34:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:05:52 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_find_smallest_square(t_fillist *list)
{
	int			i;
	int			size_min;
	int			j;

	i = 0;
	size_min = 0;
	while (list)
	{
		j = 0;
		while (list->tetros[j++])
			i++;
		list = list->next;
	}
	while (size_min * size_min < i)
		size_min++;
	return (size_min);
}

char			**ft_malloc_tab(t_fillist *list, char **res, int tb_size)
{
	int				i;
	int				j;
	int				res_min;

	j = 0;
	printf("res_min = %d\n", res_min = ft_find_smallest_square(list));
	//square_size = (res_min / 4) + 1;
	if (!(res = (char**)malloc(sizeof(char*) * (res_min + tb_size + 1))))
		return (NULL);
	while (j < res_min)
	{
		i = 0;
		if (!(res[j] = (char*)malloc(sizeof(char) * (res_min + tb_size + 1))))
			return (NULL);
		while (i < res_min)
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
