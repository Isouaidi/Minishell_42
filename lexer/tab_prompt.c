/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:44:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/23 15:41:29 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	getargs(t_stru *stru, char *str)
{
	stru->args = split_line(str, stru, 0);
	all_quotes(stru);
}

void	print_tab(t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->args[i])
	{
		printf("Tab_num arg: = %d\n", i);
		printf("tab_arg : %s\n", stru->args[i]);
		i++;
	}
}
