/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-haja <sal-haja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:33:50 by sal-haja          #+#    #+#             */
/*   Updated: 2023/05/24 11:01:34 by sal-haja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				bytes_read;
	int				n;
	struct s_node	str_lines;

	n = 1024;
	str_lines 
	do {
		char buff[n];
		bytes_read = read(fd, buff, );

		if (bytes_read)
			copy_to_lnl(buff, str_lines);
	}
	while(bytes_read != 0);
	
	return str_lines;
}
