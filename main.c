/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:44:42 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:06:08 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int			fd;
	char	*err_str;

	err_str = "usage: ./fillit target_file\n";
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_read_and_store_file(fd);
	}
	else
		ft_putstr(err_str);
}
