/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:07:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/25 17:47:44 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_stru		stru;
	t_parser	*pars;
	char		*txt;

	pars = NULL;
	while (1)
	{
		set_signal_action();
		txt = readline("Minishell >> ");
		getargs(&stru, txt);
		list_add(pars, &stru);
		add_history(txt);
		free(txt);
	}
	return (0);
}
