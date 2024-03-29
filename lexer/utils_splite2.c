/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_splite2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:24:31 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/27 17:25:15 by isouaidi         ###   ########.fr       */
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
