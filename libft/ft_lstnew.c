/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:47:15 by jgarside          #+#    #+#             */
/*   Updated: 2023/06/01 12:47:20 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//'ft_lstnew' creates a new node for a linked list
// with the given content and sets its next pointer to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	t_list	*new_node;

	// Create a new node with some content
	new_node = ft_lstnew("Hello, world!");
	// Print the content of the new node
	printf("Content: %s\n", (char *)new_node->content);
	printf("Next: %p\n", (void *)new_node->next);
	// Free the memory allocated for the new node
	free(new_node);
	return (0);
}
*/