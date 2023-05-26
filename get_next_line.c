/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-haja <sal-haja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:33:50 by sal-haja          #+#    #+#             */
/*   Updated: 2023/05/26 13:07:52 by sal-haja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				bytes_read;
	struct s_node	*str_lines;
	char			buff[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	str_lines = malloc(sizeof(struct s_node));
	if (!str_lines)
		return (NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read)
			copy_to_lnl(str_lines, buff);
	}
	if (str_lines)
		return (make_char(str_lines));
	return (NULL);
}
