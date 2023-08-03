/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wild_card.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:01 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/11/14 16:46:52 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_back_wild_card(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 0)
				str[i][j] *= -1;
			j++;
		}
		i++;
	}
}

void	replace_wild_card(char *str)
{
	while (*str)
	{
		if (*str == Q_DOUBLE)
		{
			str++;
			while (*str != Q_DOUBLE)
			{
				if (*str == '*')
					*str *= -1;
				str++;
			}
		}
		if (*str == Q_SINGLE)
		{
			str++;
			while (*str != Q_SINGLE)
			{
				if (*str == '*')
					*str *= -1;
				str++;
			}
		}
		str++;
	}
}
