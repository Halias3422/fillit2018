/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 14:06:50 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 12:58:07 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static t_fillist	*ft_fill_block(char *block, t_fillist *list, int tetros_nb)
{
	int				i;
	int				j;
	int				k;
	char			letter;

	i = 0;
	j = -1;
	k = 0;
	letter = 'A';
	while (++j < 4)
	{
		if (!(list->tetros[j] = (char*)malloc(sizeof(char) * 4 + 1)))
			return (NULL);
		while (i < 4)
		{
			list->tetros[j][i] = block[k++];
			if (list->tetros[j][i] == '#')
				list->tetros[j][i] = letter + tetros_nb;
			i++;
		}
		list->tetros[j][i] = '\0';
		i = 0;
	}
	list->tetros[j] = NULL;
	return (list);
}

static t_fillist	*ft_malloc_block(char *block, int tetros_nb)
{
	t_fillist		*list;

	if (!(list = (t_fillist*)malloc(sizeof(t_fillist))))
		return (NULL);
	list->tetro_nb = tetros_nb;
	if (!(list->tetros = (char**)malloc(sizeof(char*) * 4 + 1)))
		return (NULL);
	list = ft_fill_block(block, list, tetros_nb);
	if (list->tetro_nb > 25)
	{
		write(1, "error\n", 6);
		exit(-1);
	}
	list->next = NULL;
	return (list);
}

static t_fillist	*ft_list_back(t_fillist *head, t_fillist *list)
{
	t_fillist		*tmp;

	tmp = NULL;
	if (head == NULL)
		head = list;
	else
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = list;
	}
	return (head);
}

t_fillist			*ft_fill_list(char *f_cont, t_fillist *list)
{
	t_fillist		*head;
	char			*block;
	int				i;
	int				j;
	int				tetros_nb;

	head = NULL;
	if (!(block = ft_strnew(15)))
		return (NULL);
	i = 0;
	tetros_nb = 0;
	while (f_cont[i])
	{
		j = 0;
		while (j < 16)
			f_cont[i] == '\n' ? i++ : (block[j++] = f_cont[i++]);
		block[j] = '\0';
		list = ft_malloc_block(block, tetros_nb);
		head = ft_list_back(head, list);
		tetros_nb++;
		if (f_cont[i] == '\n' && f_cont[i + 1] == '\0')
			i++;
	}
	free (block);
	return (head);
}
