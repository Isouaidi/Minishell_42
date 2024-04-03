/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/02 16:03:15 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	erreurs(t_stru *stru)
{
	if (stru->er_pipe > 0)
		return (1);
	if (stru->er_tok > 0)
		return (2);
	return (0);
}

int	print_erreur(t_stru *stru)
{
	if (erreurs(stru) == 1)
	{
		printf("check your pipes\n");
		return (1);
	}
	if (erreurs(stru) == 2)
	{
		printf("check your tokkens\n");
		return (1);
	}
	return (0);
}
void	pipe_end(t_stru *stru, t_parser *list)
{
	while (list->next != NULL)
		list = list->next;
	printf("val = %s\n", list->val);
	printf("val = %d\n", list->tokken);
	if (list->tokken == 1 && list->next->val == NULL)
		stru->er_pipe = 1;
}
