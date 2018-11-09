/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_tetro_placement.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 11:55:23 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 15:01:30 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_find_form(t_fillist *list, int x, int y, char *form)
{
	int			hash_nb;
	int			i;
	int			done;
	char		tetro_symb;

	hash_nb = 0;
	i = 0;
	done = 0;
	tetro_symb = 'A' + list->tetro_nb;
	while (done == 0 && y < 4 && x < 4)
	{
		while (list->tetros[y][x + 1] == (tetro_symb) && done == 0 && x < 4)
		{
			ft_putstr("droite\n");
			form[i++] = 'd';
			x++;
		}
		done++;
		while (list->tetros[y][x - 1] == ('A' + list->tetro_nb) && done == 1)
		{
			ft_putstr("\ngauche\n");
			form[i++] = 'g';
			x--;
		}
		done++;
		if (list->tetros[y + 1][x] == ('A' + list->tetro_nb))
		{
			ft_putstr("\nbas\n");
			form[i++] = 'b';
			y++;
			done = 0;
		}
		form[i] = '\0';
	printf("APRES:\ndone = %d\ny = %d\nx = %d\ni = %d\nform[%d] = %c\n\n\n", done, y, x, i, i - 1, form[i - 1]);
	}
	return (form);
}

char			*ft_verif_form(t_fillist *list, char *form)
{
	int			y;
	int			x;
	int			i;

	y = 0;
	i = 0;
	while (list->tetros[y] && list->tetros[y][x] != 'A' + list->tetro_nb)
	{
		x = 0;
		while (list->tetros[y][x] != ('A' + list->tetro_nb) && x < 4)
			x++;
		if (list->tetros[y][x] != ('A' + list->tetro_nb))
			y++;
	}
	if (!(form = ft_strnew(9)))
		return (NULL);
	printf("BEFORE:x = %d\ny = %d\n", x, y);
	form = ft_find_form(list, x, y, form);
	return (form);
}

int				ft_init_verif(char **res, t_fillist *list, int ver, int hor)
{
	char		*form;

	res = 0;
	ver = 0;
	hor = 0;
	form = NULL;
	form = ft_verif_form(list, form);
	printf("form = %s\n", form);
	return (1);
}
