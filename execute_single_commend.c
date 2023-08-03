/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_commend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:02 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:56 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_and_close(char **cmd_arr, int stdin_backup, int stdout_backup)
{
	split_free(cmd_arr);
	dup2(stdin_backup, STDIN);
	close(stdin_backup);
	dup2(stdout_backup, STDOUT);
	close(stdout_backup);
	return (1);
}

int	execute_single_command(t_symbol *symbol, int pipe_cnt, int stdin_backup)
{
	char	**cmd_arr;
	int		stdout_backup;

	cmd_arr = make_cmd_arr(symbol);
	stdout_backup = dup(STDOUT);
	if (!pipe_cnt)
	{
		if (is_built_in(cmd_arr))
		{
			if (dup_redirection(symbol, stdin_backup, 0) < 0)
				return (free_and_close(cmd_arr, stdin_backup, stdout_backup));
			execute_built_in(cmd_arr, pipe_cnt);
			return (free_and_close(cmd_arr, stdin_backup, stdout_backup));
		}
	}
	if (cmd_arr)
		split_free(cmd_arr);
	close(stdout_backup);
	return (0);
}
