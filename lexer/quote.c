/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:33:56 by mirio             #+#    #+#             */
/*   Updated: 2024/03/25 14:24:36 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_quotes(t_stru *stru)
{
	int	i;
	int	j;

	i = 0;
	while (stru->args[i])
	{
		solo_quote(stru, 0, i);
		j = 0;
		while (stru->args[i][j])
		{
			if (stru->args[i][j] == '\'' && stru->d == 0 && stru->s == 0)
				j = simple_q(j, 0, i, stru);
			else if (stru->args[i][j] == '"' && stru->s == 0 && stru->d == 0)
				j = double_q(j, 0, i, stru);
			final_part(stru, j, i);
			j++;
		}
		check_quote(stru);
		i++;
	}
	// if (stru->er_quote < 1)
	// 	print_tab(stru);
	// stru->er_quote = 0;
}
