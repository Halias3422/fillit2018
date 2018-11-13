/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_tetro_placement.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 11:55:23 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 16:29:18 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** CO = COORDINATES AND INDEX (because of norm):
** co[0] = x
** co[1] = y
** co[2] = index
** co[3] = done
*/

static char			*ft_fill_form(char **tetros, int *co, char *form, 
					char t_symb)
{
	while (co[3] == 0 && co[1] < 4 && co[0] < 4)
	{
		while (tetros[co[1]][co[0] + 1] == t_symb && co[0]++ >= 0)
			form[co[2]++] = 'd';
		while (tetros[co[1]][co[0] - 1] == t_symb && co[3] == 0 && co[0]-- >= 0)
			form[co[2]++] = 'g';
		co[3]++;
		while (tetros[co[1]][co[0] + 1] == t_symb && co[3] == 1)
		{
			if (tetros[co[1] + 1] && tetros[co[1] + 1][co[0]] == t_symb)
			{
				form[co[2]++] = 'b';
				co[1]++;
				co[3] = 0;
				break ;
			}
			form[co[2]++] = 'd';
			co[0]++;
		}
		if (tetros[co[1] + 1] && tetros[co[1] + 1][co[0]] == t_symb &&
				co[1]++ >= 0 && co[3]-- >= 0)
			form[co[2]++] = 'b';
	}
	form[co[2]] = '\0';
	return (form);
}

static char			*ft_find_form(t_fillist *list, int x, int y, char *form)
{
	char		t_symb;
	int			co[4];

	t_symb = 'A' + list->tetro_nb;
	co[0] = x;
	co[1] = y;
	co[2] = 0;
	co[3] = 0;
	form = ft_fill_form(list->tetros, co, form, t_symb);
	return (form);
}

static char			*ft_verif_form(t_fillist *list, char *form)
{
	int			y;
	int			x;
	int			i;
	char		tetro_symb;

	tetro_symb = 'A' + list->tetro_nb;
	y = 0;
	i = 0;
	x = 0;
	while (list->tetros[y] && list->tetros[y][x] != ('A' + list->tetro_nb))
	{
		x = 0;
		while (list->tetros[y][x] != 'A' + list->tetro_nb && x < 4)
			x++;
		if (list->tetros[y][x] != 'A' + list->tetro_nb)
			y++;
	}
	if (!(form = ft_strnew(9)))
		return (NULL);
	form = ft_find_form(list, x, y, form);
	return (form);
}

int				ft_verif_place(char **res, int y, int x, char *form)
{
	int			i;
	int			check;

	i = -1;
	check = 0;
	while (++i >= 0 && res[y] && res[y][x] && form[i])
	{
		if (res[y][x + 1] && form[i] == 'd' && res[y][x + 1] == '.' && x++ >= 0)
			check++;
		if (res[y][x - 1] && form[i] == 'g' && res[y][x - 1] == '.' && x-- >= 0)
			check++;
		if (res[y + 1] && form[i] == 'b' && res[y + 1][x] == '.' && y++ >= 0)
			check++;
	}
	if (check == (int)ft_strlen(form))
			return (1);
	return (-1);
}

int				ft_init_verif(char **res, t_fillist *list, int y, int x)
{
	char		*form;
	char		tetro_symb;
	int			i;

	i = 0;
	tetro_symb = 'A' + list->tetro_nb;
	form = NULL;
	form = ft_verif_form(list, form);
	if (ft_verif_place(res, y, x, form) == 1)
	{
		res[y][x] = tetro_symb;
		while (form[i])
		{
			if (form[i] == 'd')
				res[y][++x] = tetro_symb;
			if (form[i] == 'g')
				res[y][--x] = tetro_symb;
			if (form[i] == 'b')
				res[++y][x] = tetro_symb;
			i++;
		}
		return (1);
	}
	return (-1);
}
