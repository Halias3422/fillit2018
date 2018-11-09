/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:41:45 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 14:23:14 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				fd;
	char			*err_str;
	char			*f_cont;
	t_fillist		*list;
	char			**res;
	int				j;

	j = 0;
	list = NULL;
	err_str = "usage: ./fillit target_file\n";
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		f_cont = ft_read_and_store_file(fd);
		close(fd);
		list = ft_fill_list(f_cont, list);
/*		while (list)
		{
			j = 0;
			while (list->tetros[j])
			{
				printf("%s\n", list->tetros[j]);
				j++;
			}
			list = list->next;
		}*/
		res = ft_create_res_tab(list);
		j = 0;
			while (res[j])
		{
			printf("EMPTYres[%d] = %s\n", j, res[j]);
			j++;
		}
		res = ft_initiate_fill_res_tab(list, res);
/*		j = 0;
		while (res[j])
		{
			printf("FULLres[%d] = %s\n", j, res[j]);
			j++;
		}*/
	}
	else
		ft_putstr(err_str);
}
