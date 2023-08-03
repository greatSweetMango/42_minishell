/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:39 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:09 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	recognize_echo_option(char *str)
{
	if (*str != '-')
		return (0);
	++str;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		++str;
	}
	return (1);
}

void	ft_echo(char **arg, int pipe_cnt)
{
	int		idx;
	int		new_line;
	void	(*f_exit)(int);

	f_exit = set_exit_code;
	if (pipe_cnt)
		f_exit = exit;
	(void)pipe_cnt;
	new_line = 1;
	idx = 1;
	while (arg[idx] && recognize_echo_option(arg[idx]))
		++idx;
	if (idx == 1)
		new_line = 0;
	while (arg[idx])
	{
		write(1, arg[idx], ft_strlen(arg[idx]));
		++idx;
		if (arg[idx])
			write(1, " ", 1);
	}
	if (!new_line)
		write(1, "\n", 1);
	f_exit(0);
}
