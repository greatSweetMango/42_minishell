/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:42 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:11 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **arg, int pipe_cnt)
{
	t_envlst	*tmp;

	tmp = g_info->envlst;
	if (arg[1])
	{
		print_error("env: ", arg[1], ": No such file or directory", -2);
		if (pipe_cnt)
			exit(127);
		set_exit_code(127);
		return ;
	}
	while (tmp)
	{
		if (tmp->value)
		{
			write(1, tmp->key, ft_strlen(tmp->key));
			write(1, "=", 1);
			write(1, tmp->value, ft_strlen(tmp->value));
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	if (pipe_cnt)
		exit(0);
	set_exit_code(0);
}
