/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:22:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 18:38:05 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_initiate_fill_res_tab(t_fillist *list, char **res)
{
	int			hor;
	int			ver;
	int			i = 0;

	ver = 0;
	while (res[ver] && list != NULL)
	{
		hor = 0;
		while (res[ver][hor] && list != NULL)
		{
			if (res[ver][hor] == '.')
			{
				if ((ft_init_verif(res, list, ver, hor)) == 1)
				{
					hor = 0;
					ver = 0;
					i = 0;
					while (res[i])
					{
						printf("res[%d] = %s\n", i, res[i]);
						i++;
					}
					list = list->next;
				}
			}
			hor++;
		}
		ver++;
	}
	if (ver == (int)ft_strlen(res[ver - 1]))
	{
		ft_putstr("au secours");
	}
	return (res);
}
