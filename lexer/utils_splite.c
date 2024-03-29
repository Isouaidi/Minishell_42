/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_splite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:25:08 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/27 17:26:37 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*split_line_part2(char **list, char *str, t_stru *stru)
{
	if (t_split(*str) != 0)
	{
		if ((*str == '>' && *(str + 1) == '>')
			|| (*str == '<' && *(str + 1) == '<')
			|| (t_split(*str) != 0 && *(str + 1) == '<' && *(str + 2) == '<')
			|| (t_split(*str) != 0 && *(str + 1) == '>' && *(str + 2) == '>'))
		{
			str = redirections(list, str, stru);
			str = redirections1(list, str, stru);
			str = redirections2(list, str, stru);
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

char	*redirections1(char **list, char *str, t_stru *stru)
{
	if ((t_split(*str) != 0) && *(str + 1) == '<' && *(str + 2) == '<' )
	{
		list[stru->i] = ft_calloc(2, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = t_split(*str);
		list[stru->i][1] = '\0';
		stru->i++;
		list[stru->i] = ft_calloc(3, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = '<';
		list[stru->i][1] = '<';
		list[stru->i][2] = '\0';
		str = str + 3;
		stru->i++;
		return (str);
	}
	return (str);
}

char	*redirections2(char **list, char *str, t_stru *stru)
{
	if ((t_split(*str) != 0) && *(str + 1) == '>' && *(str + 2) == '>' )
	{
		list[stru->i] = ft_calloc(2, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = t_split(*str);
		list[stru->i][1] = '\0';
		stru->i++;
		list[stru->i] = ft_calloc(3, sizeof(char));
		if (!list[stru->i])
			return (NULL);
		list[stru->i][0] = '>';
		list[stru->i][1] = '>';
		list[stru->i][2] = '\0';
		str = str + 3;
		stru->i++;
		return (str);
	}
	return (str);
}
