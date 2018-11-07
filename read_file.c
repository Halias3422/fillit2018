/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 12:22:22 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 14:35:50 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_check_line(int i, int j, int nb_line, char *f_cont)
{
	while (f_cont[i])
	{
		while (j < 4)
		{
			if (f_cont[i] == '.' || f_cont[i] == '#')
			{
				i++;
				j++;
			}
			else
				return (-1);
		}
		nb_line++;
		if (nb_line % 4 == 0 && f_cont[i] == '\n' && f_cont[i + 1] == '\n'
				&& f_cont[i + 2] != '\0')
			i = i + 2;
		else if (nb_line % 4 == 0 && f_cont[i] == '\n' && f_cont[i + 1] == '\0')
			return (1);
		else if (nb_line % 4 != 0 && f_cont[i] == '\n')
			i++;
		else
			return (-1);
		j = 0;
	}
	return (1);
}

static int			ft_check_symb(int i, int j, char *f_cont)
{
	int				nb_symb;

	while (f_cont[i])
	{
		nb_symb = 0;
		while (j < 20)
		{
			if (f_cont[i] == '#' && ((f_cont[i - 1] == '#' ||
				f_cont[i + 1] == '#' || f_cont[i + 5] == '#' ||
				f_cont[i - 5] == '#')))
				nb_symb++;
			else if (f_cont[i] == '#')
				return (-1);
			i++;
			j++;
		}
		j = 0;
		if (nb_symb == 4 && f_cont[i + 1] == '\0')
			return (1);
		if (nb_symb != 4)
			return (-1);
		while (f_cont[i] == '\n')
			i++;
	}
	return (1);
}

static int			ft_check_errors(char *f_cont)
{
	int				i;
	int				j;
	int				not_error;
	int				nb_line;

	nb_line = 0;
	i = 0;
	j = 0;
	not_error = -1;
	if (ft_check_line(i, j, nb_line, f_cont) == 1)
		not_error++;
	if (not_error == 0 && ft_check_symb(i, j, f_cont) == 1)
		not_error++;
	return (not_error);
}

char				*ft_read_and_store_file(int fd)
{
	char			*line;
	int				error;
	char			*f_cont;
	char			*tmp;

	f_cont = ft_strnew(1);
	error = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(f_cont, line);
		free(f_cont);
		f_cont = tmp;
		free(line);
	}
	if (ft_check_errors(f_cont) != 1)
	{
		write(1, "error\n", 6);
		exit(-1);
	}
	return (f_cont);
}