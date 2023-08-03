/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:38 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:45:07 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **arg, int pipe_cnt)
{
	t_cd	*cd_info;

	if (!arg[1])
		ft_cd_home(pipe_cnt);
	else
	{
		cd_info = ft_init_cd_info(pipe_cnt, arg[1]);
		if (arg[1][0] == '~')
		{
			cd_info->rv = chdir("/");
			cd_info->rv = chdir(g_info->home);
			if (arg[1][1] && arg[1][1] == '/' && arg[1][2])
				cd_info->rv = chdir(&arg[1][2]);
			else if (arg[1][1] && arg[1][1] != '/')
				cd_info->rv = -1;
		}
		else
			cd_info->rv = chdir(arg[1]);
		ft_check_rv(cd_info);
		free(cd_info);
	}
}
