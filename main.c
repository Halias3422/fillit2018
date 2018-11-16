/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:41:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 15:04:37 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char			**ft_functions_call(t_fillist *list, char **res)
{
	int				*coord;
	t_fillist		*head;

	head = list;
	if (!(coord = (int*)malloc(sizeof(int) * 3)))
		return (NULL);
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	res = ft_fill_res_tab(list, res, coord);
	return (res);
}

void				ft_aff_res(char **str)
{
	int				i;

	i = 0;
	while (str[i])
		ft_putendl(str[i++]);
}

int					main(int ac, char **av)
{
	int				fd;
	char			*err_str;
	char			*f_cont;
	t_fillist		*list;
	char			**res;

	list = NULL;
	err_str = "usage: ./fillit target_file\n";
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		f_cont = ft_read_and_store_file(fd);
		close(fd);
		list = ft_fill_list(f_cont, list);
		free (f_cont);
		res = ft_create_res_tab(list);
		res = ft_functions_call(list, res);
		free (list);
		ft_aff_res(res);
		free (res);
	}
	else
		ft_putstr(err_str);
	return (0);
}
