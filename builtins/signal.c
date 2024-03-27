/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:42:31 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/26 13:57:00 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sign( int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal_action(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = sign;
	sigaction(SIGINT, &act, NULL);
	//bzero(&act, sizeof(act));
    act.sa_handler = SIG_IGN; // Ignorer le signal
    sigaction(SIGQUIT, &act, NULL);
}
