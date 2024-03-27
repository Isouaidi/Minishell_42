/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:24:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/22 14:51:34 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	solo_quote(t_stru *stru, int j, int i)
{
	stru->d = 0;
	stru->s = 0;
	stru->dquote = 0;
	stru->squote = 0;
	j = ft_strlen(stru->args[i]);
	if (j == 1)
	{
		if (stru->args[i][0] == '"' || stru->args[i][0] == '\'')
		{
			printf("check your quote");
			new_display();
			stru->er_quote = 1;
		}
	}
}

int	simple_q(int j, int w, int i, t_stru *stru)
{
	w = j;
	while (stru->args[i][w])
	{
		if (stru->args[i][w] == '\'' )
		{
			stru->s = 1;
			stru->squote++;
			j++;
			break ;
		}
		w++;
	}
	return (j);
}

int	double_q(int j, int q, int i, t_stru *stru)
{
	q = j;
	while (stru->args[i][q])
	{
		if (stru->args[i][q] == '"' )
		{
			stru->d = 1;
			stru->dquote++;
			j++;
			break ;
		}
		q++;
	}
	return (j);
}

void	final_part(t_stru *stru, int j, int i)
{
	if (stru->args[i][j] == '\'' && stru->d == 0)
		stru->squote ++;
	if (stru->args[i][j] == '"' && stru->s == 0)
		stru->dquote ++;
	if (stru->args[i][j] == '\'' && stru->s == 1)
		stru->s = 0;
	if (stru->args[i][j] == '"' && stru->d == 1)
		stru->d = 0;
}

void	check_quote(t_stru *stru)
{
	if ((stru->squote % 2 != 0 || stru->dquote % 2 != 0) && stru->er_quote != 1)
	{
		printf("check your quote");
		new_display();
		stru->er_quote = 2;
	}
}
