/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brace_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:44:08 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:31 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*brace_group(t_symbol *symbol)
{
	t_symbol	*temp;

	symbol = symbol->next;
	if (symbol->pre)
		symbol->pre->next = NULL;
	free_symbol(symbol->pre);
	symbol->pre = NULL;
	temp = get_last_symbol(symbol);
	temp = temp->pre;
	if (temp->next)
		temp->next->pre = NULL;
	free_symbol(temp->next);
	temp->next = NULL;
	return (and_or(symbol));
}
