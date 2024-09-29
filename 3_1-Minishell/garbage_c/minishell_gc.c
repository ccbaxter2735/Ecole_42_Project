/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:46:36 by pduhamel          #+#    #+#             */
/*   Updated: 2023/10/05 16:34:36 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//MARK : auto in gc || arg = size | vars | TEMP or PERM | number
void	*gc_malloc(size_t size, t_vars *vars, int status, int index)
{
	void		*addr;
	t_list_gc	*new;

	addr = malloc(size);
	if (!addr)
		return (ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	new = malloc(sizeof(t_list_gc));
	if (!new)
		return (free(addr), ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	new->addr_obj = addr;
	new->status = status;
	new->index = index;
	new->next = vars->list_gc;
	vars->list_gc = new;
	return (addr);
}

//MARK : show the garbage
void	print_garbage(t_list_gc *bordel)
{
	t_list_gc	*current;

	current = bordel;
	if (current == NULL)
		printf("Garbage empty...\n");
	while (current)
	{
		printf("%d - %p\n", current->index, current->addr_obj);
		current = current->next;
	}
}

//MARK : Delete objects by status or index or addr
void	gc_del(t_list_gc *bordel, int status, int index, void *addr)
{
	t_list_gc	*current;
	t_list_gc	*tmp;

	current = bordel;
	if (!current || !current->next)
		return ;
	while (current && current->next)
	{
		if (status == UNUSED && ((current->next)->index == index
				|| ((current->next)->addr_obj == addr)))
		{
			tmp = current->next;
			current->next = tmp->next;
			free(tmp->addr_obj);
			free(tmp);
		}
		if (index == UNUSED && (current->next)->status == status)
		{
			tmp = current->next;
			current->next = tmp->next;
			free(tmp->addr_obj);
			free(tmp);
		}
		current = current->next;
	}
}

//MARK : clear all the GC
void	gc_clear(t_list_gc *bordel)
{
	t_list_gc	*current;
	t_list_gc	*tmp;

	current = bordel;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->addr_obj);
		free(tmp);
	}
}
