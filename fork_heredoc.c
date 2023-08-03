/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:14 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 17:10:06 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_heredoc_tmp_str(int i)
{
	char	*no_ps;
	char	*filename;
	char	*rv_str;

	no_ps = ft_itoa(i);
	filename = ft_strjoin("/", no_ps);
	free(no_ps);
	rv_str = ft_strjoin(g_info->home, filename);
	free (filename);
	return (rv_str);
}

int	fork_heredoc(char *limiter, int stdin_backup, char *heredoc_tmp)
{
	int	pid;
	int	exitcode;

	pid = fork();
	if (pid == 0)
	{
		set_child_signal();
		read_here_doc(limiter, stdin_backup, heredoc_tmp);
	}
	else
	{
		block_signal();
		waitpid(pid, &exitcode, 0);
		if (WIFSIGNALED(exitcode) && WTERMSIG(exitcode) == 2)
		{
			g_info->flag = 1;
			set_exit_code(1);
			set_signal();
			return (-1);
		}
	}
	set_signal();
	return (0);
}
