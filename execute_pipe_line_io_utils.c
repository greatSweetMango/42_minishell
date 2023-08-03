/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_line_io_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:44:50 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 17:10:09 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_after_rid(t_symbol *symbol)
{
	int	cnt;

	cnt = 0;
	symbol = symbol->next->next;
	while (symbol && symbol->type != T_CMD && symbol->type != T_PIPE)
	{
		if (symbol->type == T_IN_HEREDOC || symbol->type == T_IN_RID)
			cnt++;
		symbol = symbol->next->next;
	}
	return (cnt);
}

int	task_here_doc(t_symbol *symbol, int *fd, int stdin_backup, int i)
{
	int		rv;
	char	*heredoc_tmp;

	heredoc_tmp = make_heredoc_tmp_str(i);
	if (fork_heredoc(symbol->next->str, stdin_backup, heredoc_tmp) < 0)
	{
		free(heredoc_tmp);
		return (-1);
	}
	if (count_after_rid(symbol))
		rv = 0;
	else
	{
		*fd = open_file(heredoc_tmp, T_IN_RID);
		if (*fd < 0)
			rv = -1;
		else
			rv = DID_IN_RID;
	}
	unlink(heredoc_tmp);
	free(heredoc_tmp);
	return (rv);
}

void	dup_parant_pipe(int *fd_pipe, int stdout_backup)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], STDIN);
	dup2(stdout_backup, STDOUT);
	close(stdout_backup);
}

void	dup_child_pipe(int *fd_pipe, int flag, int pipe_cnt, int i)
{
	close(fd_pipe[0]);
	if (flag <= 1 && i != pipe_cnt)
		dup2(fd_pipe[1], STDOUT);
	if (flag < 0)
		exit(1);
}

int	len_cmp(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
