/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_splite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:25:08 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/23 00:21:45 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	t_split(char c)
{
	if (c == '|')
		return (c);
	if (c == '<')
		return (c);
	if (c == '>')
		return (c);
	return (0);
}

char	*split_line_part2(char **list, char *str, t_stru *stru)
{
	if (t_split(*str) != 0)
	{
		if ((*str == '>' && *(str + 1) == '>')
			|| (*str == '<' && *(str + 1) == '<'))
		{
			str = redirections(list, str, stru);
			return (str);
		}
		else
			str = other_tok(list, str, stru);
	}
	return (str);
}

char	*split_line_part3(char *str, char *quote)
{
	while ((*str == ' ' ) && !(*quote) && *str)
		str += iterate(quote, *str);
	return (str);
}

char	*redirections(char **list, char *str, t_stru *stru)
{
	if (*str == '>' && *(str + 1) == '>')
	{
		list[stru->i] = ft_calloc (3, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = '>';
		list[stru->i][1] = '>';
		list[stru->i][2] = '\0';
		str = str + 2;
		stru->i++;
		return (str);
	}
	if (*str == '<' && *(str + 1) == '<')
	{
		list[stru->i] = ft_calloc(3, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = '<';
		list[stru->i][1] = '<';
		list[stru->i][2] = '\0';
		str = str + 2;
		stru->i++;
		return (str);
	}
	return (str);
}

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
