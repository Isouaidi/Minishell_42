/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:18:08 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/22 19:54:41 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_display(void)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

int	tok(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (t_split(str[i]) != 0)
			count += 2;
		i++;
	}
	return (count);
}
