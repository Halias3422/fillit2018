/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:41:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:33:31 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char			**ft_functions_call(t_fillist *list, char **res)
{
	int				*coord;
	t_fillist		*link;

	link = list;
	if (!(coord = (int*)malloc(sizeof(coord) * 3)))
		return (NULL);
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	res = ft_fill_res_tab(list, res, coord, link);
	free(coord);
	return (res);
}

static char			**ft_aff_res(char **str)
{
	int				i;

	i = 0;
	while (str[i])
		ft_putendl(str[i++]);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (str);
}

static void			ft_free_list(t_fillist **list)
{
	t_fillist		*lst;
	t_fillist		*data;
	int				i;

	data = *list;
	while (data)
	{
		i = 0;
		lst = data->next;
		while (data->tetros[i])
			free(data->tetros[i++]);
		free(data->tetros);
		free(data->form);
		data->tetro_nb = 0;
		free(data);
		data = lst;
	}
	*list = NULL;
}

void				ft_error(void)
{
	ft_putendl("error");
	exit(-1);
}

int					main(int ac, char **av)
{
	int				fd;
	char			*err_str;
	char			*f_cont;
	t_fillist		*list;
	char			**res;

	f_cont = NULL;
	list = NULL;
	err_str = "usage: ./fillit target_file\n";
	if (ac == 2)
	{
		((fd = open(av[1], O_RDWR)) == -1) ? ft_error() : 0;
		f_cont = ft_read_and_store_file(fd);
		close(fd);
		list = ft_fill_list(f_cont, list);
		free(f_cont);
		res = ft_create_res_tab(list);
		res = ft_functions_call(list, res);
		res = ft_aff_res(res);
		ft_free_list(&list);
	}
	else
		ft_putstr(err_str);
	return (0);
}
