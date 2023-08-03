/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:41:01 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:44:31 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(char *cmd, char *path)
{
	struct stat	sb;
	char		*rv_cmd;

	while (*path)
	{
		rv_cmd = ft_strjoin_free(ft_strjoin_free(ft_strndup(path,
						ft_strichr(path, ':')), "/"), cmd);
		if (!rv_cmd)
			allocat_error();
		if (stat(rv_cmd, &sb) >= 0)
			return (rv_cmd);
		free(rv_cmd);
		if (ft_strichr(path, ':') >= 0)
			path += ft_strichr(path, ':') + 1;
		else
			path += ft_strlen(path);
	}
	if (stat(cmd, &sb) >= 0)
		return (ft_strdup(cmd));
	return (NULL);
}

int	is_cmd(char	*str)
{
	char	*path;
	char	*cmd_path;

	path = get_env("PATH");
	cmd_path = get_cmd_path(str, path);
	free(path);
	if (cmd_path)
	{
		free(cmd_path);
		if (errno == ENOENT)
			return (0);
	}
	return (1);
}
