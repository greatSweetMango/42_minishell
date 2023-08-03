/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parse_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:44:10 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:33 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*make_token(t_symbol *symbol)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		exit(-1);
	token->symbol = symbol;
	token->left = NULL;
	token->right = NULL;
	return (token);
}

t_token	*make_parse_tree(t_symbol *symbol)
{
	t_token			*tree_root;

	tree_root = and_or(symbol);
	return (tree_root);
}
