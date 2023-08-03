/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:44:06 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:29 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*and_or(t_symbol *symbol)
{
	t_token		*token;
	t_symbol	*curr;

	curr = get_last_symbol(symbol);
	while (curr)
	{
		if (curr->type == T_OR_IF || curr->type == T_AND_IF)
		{
			token = make_token(curr);
			if (curr->pre)
				curr->pre->next = NULL;
			if (curr->next)
				curr->next->pre = NULL;
			token->left = and_or(symbol);
			token->right = pipeline(curr->next);
			curr->pre = NULL;
			curr->next = NULL;
			return (token);
		}
		else if (curr->type == T_RBRACE)
			curr = skip_brace(curr->pre);
		if (curr)
			curr = curr->pre;
	}
	return (pipeline(symbol));
}
