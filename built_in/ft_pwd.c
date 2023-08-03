/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:50 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:19 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **arg, int pipe_cnt)
{
	char	*pwd;

	(void)arg;
	pwd = get_env("PWD");
	if (*pwd)
	{
		write(1, pwd, ft_strlen(pwd));
		write(1, "\n", 1);
		free(pwd);
		if (pipe_cnt)
			exit(0);
		set_exit_code(0);
	}
	else
	{
		if (pipe_cnt)
			exit(1);
		set_exit_code(1);
	}
}
