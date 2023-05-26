/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-haja <sal-haja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:33:59 by sal-haja          #+#    #+#             */
/*   Updated: 2023/05/26 13:06:12 by sal-haja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

struct s_node {
	int				data;
	struct s_node	*next;
};
char	*get_next_line(int fd);
void	copy_to_lnl(struct s_node *str_lines, char buff[]);
int		linked_len(struct s_node *str);
char	*make_char(struct s_node *str);
void	clean_linkedlist(struct s_node *str_lines);

#endif