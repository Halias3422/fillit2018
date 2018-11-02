/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 12:22:22 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:06:04 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					ft_check_errors(char *file_content)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (file_content[i])
	{
		while (j <= 4)
		{
			if (file_content[i] == '.' || file_content[i] == '#')
			{
				//i++ && j++;
				i++;
				j++;
			}
			else
				return (-1);
		}
		if ((i % 16 == 0) && ((file_content[i] == '\n') && 
				(file_content[i + 1] == '\n' || file_content[i + 1] == '\0')))
			i = i + 2;
		else
		{
			if (j == '\n')
				j = 0;
		}
	}
}

//tentative desesperee de checker erreurs et remplir liste en meme temps

/*static int			ft_create_tab_and_check_errors(char *file_content)
{
	t_fillist		*list;
	int				i;
	int				j;
	int				line;
	char			*str;

	if(!(str = (char*)malloc(sizeof(char) * 5)))
		return (-1);
	i = 0;
	j = 0;
	line = 0;
	while (file_content[j])
	{
		while (i <= 4)
		{
			if (file_content[j] == '.' || file_content[j] == '#')
				str[i++] = file_content[j++];
			else
				return (-1);
		}
		fonction_pour_tab(str);
		i = 0;
		line++;
		if (line > 25)
			return (-1);
	}
	
}*/

char				*ft_read_and_store_file(int fd)
{
	char			*line;
	int				error;
	char			*file_content;
	char			*tmp;

	file_content = ft_strnew(1);
	error = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(file_content, line);
		free(file_content);
		file_content = tmp;
		free(line);
	}
//	free(tmp);
	ft_check_errors(file_content);
	return (file_content);
}
