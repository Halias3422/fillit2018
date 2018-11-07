/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 14:06:50 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:13:40 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static t_fillist	*ft_fill_block(char *block, int tetros_nb, t_fillist *head)
{
	t_fillist		*list;
	int				i;
	int				j;
	int				k;
	int				nb_list;

	nb_list = 0;
	i = 0;
	j = 0;
	k = 0;
	if (!(list = (t_fillist*)malloc(sizeof(t_fillist))))
		return (NULL);
	list->tetro_nb = tetros_nb;
	if (!(list->tetros = (char**)malloc(sizeof(char*) * 4 + 1)))
		return (NULL);
	while (j < 4)
	{
		if (!(list->tetros[j] = (char*)malloc(sizeof(char) * 4 + 1)))
			return (NULL);
		while ( i < 4)
			list->tetros[j][i++] = block[k++];
		list->tetros[j][i] = '\0';
		printf("tetros[%d] = %s\n", j, list->tetros[j]);
		i = 0;
		j++;
	}
	printf("tetro_nb = %d\n\n", tetros_nb);
	list->tetros[j] = NULL;
	list->next = head;
	return (list);
}

t_fillist			*ft_sort_list(t_fillist *head, t_fillist *list, int tetros_nb)
{
	t_fillist		*tmp;

	if (tetros_nb == 0)
		head = list;
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = list;
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
		return(NULL);
	i = 0;
	tetros_nb = 0;
	while (f_cont[i])
	{
		j = 0;
		while (j < 16)
		{
			if (f_cont[i] == '\n')
				i++;
			else
				block[j++] = f_cont[i++];
		}
		block[j] = '\0';
		list = ft_fill_block(block, tetros_nb, head);
//		head = ft_sort_list(head, list, tetros_nb);
		head = list;
		list = list->next;
		tetros_nb++;
		if (f_cont[i] == '\n' && f_cont[i + 1] == '\0')
			i++;
	}
	return (head);
}
