/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:07:33 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/06 10:37:28 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	txt_null(char *txt)
{
	if (txt == NULL)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_stru		stru;
	t_parser	*pars;
	t_cmd		*cmd;
	t_env		*v_env;
	char		*txt;
	
	(void)av;
	stru.env = env;
	v_env = NULL;
	pars = NULL;
	cmd = NULL;
	convert_env(v_env,&stru);
	if (ac == 1)
	{
		set_signal_action();
		while (1)
		{
			
			txt = readline("Minishell >> ");
			if (txt_null(txt) == 1)
				break ;
			getargs(&stru, txt);
			list_add(pars, &stru, cmd);
			free_tab(stru.args);
			add_history(txt);
			free(txt);
		}
	}
	return (0);
}
