/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-haja <sal-haja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:33:03 by sal-haja          #+#    #+#             */
/*   Updated: 2023/05/26 13:21:52 by sal-haja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void	clean_linkedlist(struct s_node *str_lines)
{
	if (!str_lines)
		return ;
	clean_linkedlist(str_lines->next);
	free(str_lines);
}

void	copy_to_lnl(struct s_node *str_lines, char buff[])
{
	static struct s_node	*node;
	int						i;

	node = str_lines;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i + 1] != '\0')
			node->next = malloc(sizeof(struct s_node));
		if (!node->next)
		{
			clean_linkedlist(str_lines);
			return ;
		}
		node->data = buff[i];
		if (buff[i + 1] != '\0')
			node = node->next;
		i++;
	}
}

int	linked_len(struct s_node *str)
{
	int						len;
	static struct s_node	*node;

	node = str;
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

char	*make_char(struct s_node *str)
{
	char					*ans;
	int						len;
	int						i;
	static struct s_node	*node;

	i = 0;
	len = linked_len(str);
	ans = malloc(len + 1);
	if (!ans)
	{
		clean_linkedlist(str);
		return (NULL);
	}
	node = str;
	while (node)
	{
		ans[i] = node->data;
		node = node->next;
		i++;
	}
	ans[i] = '\0';
	clean_linkedlist(str);
	return (ans);
}
