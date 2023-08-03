/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:21 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:46:09 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char *str)
{
	t_token	*cmd;

	cmd = parse_line(str);
	execute_tree(cmd);
	free_tree(cmd);
}

int	main(int ac, char **av, char **env)
{
	char	*str;

	if (ac != 1 && av)
		return (0);
	init_info(env);
	while (1)
	{
		set_signal();
		str = readline(C_BLUE "minihell$ " C_NRML);
		if (!str)
			exit(0);
		if (!ft_strlen(str))
		{
			free(str);
			continue ;
		}
		add_history(str);
		execute(str);
	}
	return (0);
}
