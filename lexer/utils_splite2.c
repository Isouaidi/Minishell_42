/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_splite2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:24:31 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/15 16:11:52 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*other_tok(char **list, char *str, t_stru *stru)
{
	list[stru->i] = ft_calloc(2, sizeof(char));
	if (list[stru->i] == NULL)
		return (NULL);
	list[stru->i][0] = t_split(*str);
	list[stru->i][1] = '\0';
	stru->i++;
	str++;
	while (t_split(*str) != 0)
	{
		list[stru->i] = ft_calloc(2, sizeof(char));
		if (list[stru->i] == NULL)
			return (NULL);
		list[stru->i][0] = t_split(*str);
		list[stru->i][1] = '\0';
		stru->i++;
		str++;
	}
	return (str);
}

void	pipe_begin(char *str, t_stru *stru)
{
	int	i;

	stru->er_pipe = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	if 	(i > 0)
	{
		if (str[0] == '|' || str[i] == '|')
		stru->er_pipe = 1;
	}
}
