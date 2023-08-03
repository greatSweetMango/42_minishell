/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:43 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:46:35 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_tree(t_token *tree)
{
	t_token	*right_tree;

	if (!tree)
		return ;
	if (tree->left)
		free_tree(tree->left);
	free_symbol(tree->symbol);
	right_tree = tree->right;
	free(tree);
	if (right_tree)
		free_tree(right_tree);
}

void	free_symbol(t_symbol *symbol)
{
	t_symbol	*temp;

	if (!symbol)
		return ;
	while (symbol)
	{
		free(symbol->str);
		temp = symbol->next;
		free(symbol);
		symbol = temp;
	}
}

void	free_symbols(t_symbol *symbols)
{
	t_symbol	*temp;

	while (symbols)
	{
		temp = symbols;
		free(temp->str);
		symbols = symbols->next;
		free(temp);
	}
}
