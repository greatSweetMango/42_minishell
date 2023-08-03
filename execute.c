/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:04 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:58 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_exit_code(void)
{
	if (!ft_strcmp(g_info->exit_code, "0"))
		return (0);
	else
		return (1);
}

void	execute_tree(t_token *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		execute_tree(tree->left);
	if (tree->symbol->type == T_AND_IF || tree->symbol->type == T_OR_IF)
	{
		if ((tree->symbol->type == T_AND_IF && !check_exit_code())
			|| (tree->symbol->type == T_OR_IF && check_exit_code()))
		{
			if (!g_info->flag)
				execute_tree(tree->right);
		}
	}
	else
	{
		g_info->flag = 0;
		execute_pipe_line(tree->symbol);
	}
}
