/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:21:29 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/01 16:24:29 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokken_erreur(t_parser *list, t_stru *stru)
{
	t_parser	*temp;

	if (list != NULL)
	{
		temp = list->next;
		while (list->next)
		{
			if (list->tokken != 0 && temp->tokken != 0)
				stru->er_tok = 1;
			list = list->next;
			temp = temp->next;
		}
	}
}
