/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:14 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:46:57 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_type(int type)
{
	if (type >= T_FILEPATH && type <= T_OR_IF)
		return (1);
	else if (type == T_RBRACE)
		return (1);
	return (0);
}

int	lbrace_case(t_symbol *symbol_lst)
{
	if (symbol_lst->type != T_LBRACE)
		return (0);
	if (symbol_lst->pre && !(T_PIPE <= symbol_lst->pre->type \
	&& symbol_lst->pre->type <= T_LBRACE))
		return (syntax_error_token("("));
	if (check_first_type(symbol_lst->next->type)
		&& symbol_lst->next->type != T_LBRACE)
		return (syntax_error_token(get_origin_op(symbol_lst->next->type)));
	return (0);
}

int	rbrace_case(t_symbol *symbol_lst)
{
	if (symbol_lst->type != T_RBRACE)
		return (0);
	if (symbol_lst->next->type < T_PIPE || symbol_lst->next->type == T_LBRACE)
		return (syntax_error_token(symbol_lst->next->str));
	return (0);
}

int	pipe_andif_orif_case(t_symbol *symbol_lst)
{
	if (!(symbol_lst->type >= T_PIPE && symbol_lst->type <= T_OR_IF))
		return (0);
	if (symbol_lst->next->type >= T_PIPE && \
	symbol_lst->next->type <= T_OR_IF && \
	symbol_lst->next->type != T_LBRACE)
		return (syntax_error_token(get_origin_op(symbol_lst->next->type)));
	return (0);
}

int	direction_case(t_symbol *symbol_lst)
{
	if (!(symbol_lst->type >= T_IN_RID && symbol_lst->type <= T_OUT_HEREDOC))
		return (0);
	if (symbol_lst->next->type != T_FILEPATH)
		return (syntax_error_token(get_origin_op(symbol_lst->next->type)));
	return (0);
}
