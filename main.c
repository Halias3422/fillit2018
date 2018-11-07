/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:44:42 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:03:47 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				fd;
	char		*err_str;
	char		*f_cont;
	t_fillist	*list;
	int				k;

	k = 0;
	list = NULL;
	err_str = "usage: ./fillit target_file\n";
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		f_cont = ft_read_and_store_file(fd);
		close (fd);
		list = ft_fill_list(f_cont, list);
		while(list != NULL)
		{
			while (list->tetros[k])
			{
				printf("tab[%d] = %s\n", k, list->tetros[k]);
				k++;
			}
			printf("tetro_nb = %d\n\n", list->tetro_nb);
			k = 0;
			list = list->next;
		}
/*		while (list->previous != NULL)
		{
			while (list->tetros[k])
			{
				printf("tab2[%d] = %s\n", k, list->tetros[k]);
				k++;
			}
			printf("tetro_nb = %d\n\n", list->tetro_nb);
			k = 0;
			list = list->previous;
		}
*/
	}
	else
		ft_putstr(err_str);
}
