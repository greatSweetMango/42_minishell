/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:58 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:46:49 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_space(char *str)
{
	if (*str == ' ')
		*str *= -1;
	else if (*str == '\r')
		*str *= -1;
	else if (*str == '\t')
		*str *= -1;
	else if (*str == '\f')
		*str *= -1;
	else if (*str == '\n')
		*str *= -1;
	else if (*str == '\v')
		*str *= -1;
}

char	*double_quote(char *str)
{
	while (*str)
	{
		is_space(str);
		if (*str == '\"')
			return (str);
		++str;
	}
	return (NULL);
}

char	*single_quote(char *str)
{
	while (*str)
	{
		is_space(str);
		if (*str == '\'')
			return (str);
		++str;
	}
	return (NULL);
}

void	replace_white_space(char *str)
{
	while (*str)
	{
		if (*str == '\"')
			str = double_quote(++str);
		if (*str == '\'')
			str = single_quote(++str);
		str++;
	}
}
