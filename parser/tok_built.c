/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:31:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 16:47:31 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	tokken(t_pars *list)
{
	if (list->val[0] == '|' && list->val[1] == '\0')
		return (1);
	if (list->val[0] == '>' && list->val[1] == '\0')
		return (2);
	if (list->val[0] == '>' && list->val[1] == '>' && list->val[2] == '\0')
		return (3);
	if (list->val[0] == '<' && list->val[1] == '\0')
		return (4);
	if (list->val[0] == '<' && list->val[1] == '<' && list->val[2] == '\0')
		return (5);
	return (0);
}

t_built	builtines(t_pars *list)
{
	if (list->val[0] == 'e' && list->val[1] == 'c' && list->val[2] == 'h'
		&& list->val[3] == 'o' && list->val[4] == '\0')
		return (1);
	if (list->val[0] == 'c' && list->val[1] == 'd' && list->val[2] == '\0')
		return (2);
	if (list->val[0] == 'p' && list->val[1] == 'w' && list->val[2] == 'd'
		&& list->val[3] == '\0')
		return (3);
	if (list->val[0] == 'e' && list->val[1] == 'x' && list->val[2] == 'p'
		&& list->val[3] == 'o' && list->val[4] == 'r'
		&& list->val[5] == 't' && list->val[6] == '\0')
		return (4);
	if (list->val[0] == 'u' && list->val[1] == 'n' && list->val[2] == 's'
		&& list->val[3] == 'e' && list->val[4] == 't'
		&& list->val[5] == '\0')
		return (5);
	if (list->val[0] == 'e' && list->val[1] == 'n' && list->val[2] == 'v'
		&& list->val[3] == '\0')
		return (6);
	if (list->val[0] == 'e' && list->val[1] == 'x' && list->val[2] == 'i'
		&& list->val[3] == 't' && list->val[4] == '\0')
		return (7);
	return (0);
}

void	builtines2(t_pars *list)
{
	while (list != NULL)
	{
		if (list->val[0] == 'e' && list->val[1] == 'n' && list->val[2] == 'v'
			&& list->val[3] == '\0')
			list->built = 6;
		if (list->val[0] == 'e' && list->val[1] == 'x' && list->val[2] == 'i'
			&& list->val[3] == 't' && list->val[4] == '\0')
			list->built = 7;
		list = list->next;
	}
}

void	tok_end_built(t_pars *list)
{
	while (list != NULL)
	{
		list->tokken = tokken(list);
		list->built = builtines(list);
		list = list->next;
	}
}
