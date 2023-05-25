/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-haja <sal-haja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:33:50 by sal-haja          #+#    #+#             */
/*   Updated: 2023/05/25 10:41:07 by sal-haja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_to_lnl(struct s_node *str_lines, char buff[])
{
	static struct s_node	*node;
	struct s_node			*tmp;
	int						i;

	node = str_lines;
	i = 0;
	while (buff[i] != '\0')
	{
		tmp->next = NULL;
		tmp->data = buff[i];
		*node->next = *tmp;
		node = node->next;
	}
}


char	*get_next_line(int fd)
{
	int				bytes_read;
	struct s_node	*str_lines;
	char			buff[BUFFER_SIZE];

	while (1)
	{
		bytes_read = read(fd, buff);
		if (bytes_read == 0)
			break ;
		if (bytes_read)
			copy_to_lnl(buff, str_lines);
	}
	return (str_lines);
}
