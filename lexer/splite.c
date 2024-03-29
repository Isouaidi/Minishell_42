/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:28:20 by isouaidi          #+#    #+#             */
/*   Updated: 2024/03/29 14:11:12 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	update_quote(char quote, char cur)
{
	if (!quote && (cur == '\'' || cur == '"'))
		return (cur);
	else if (quote && cur == quote)
		return (0);
	return (quote);
}

int	iterate(char *quote, char cur)
{
	*quote = update_quote(*quote, cur);
	return (1);
}

static	int	count(char *str)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (str[i])
	{
		if (((str[i] != ' ' && (t_split(str[i]) == 0)) || quote) && str[i])
		{
			while (((str[i] != ' ' && (t_split(str[i]) == 0))
					|| quote) && str[i])
			{
				i++;
				iterate(&quote, str[i]);
			}
			count++;
		}
		while ((str[i] == ' ' || (t_split(str[i]) != 0)) && !quote && str[i])
			i += iterate(&quote, str[i]);
		count += 1000;
	}
	return (count);
}

static	char	*cut_word(char *str)
{
	int		i;
	char	quote;
	char	*word;

	i = 0;
	quote = 0;
	while (((str[i] != ' ' && (t_split(str[i]) == 0)) || quote) && str[i])
		i += iterate(&quote, str[i]);
	word = ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	quote = 0;
	while (((str[i] != ' ' && (t_split(str[i]) == 0)) || quote) && str[i])
	{
		word[i] = str[i];
		iterate(&quote, str[i]);
		i++;
	}
	return (word);
}

char	**split_line(char *str, t_stru *stru, int i)
{
	char	**list;
	char	quote;

	quote = 0;
	list = ft_calloc(((count(str) + tok(str)) + 1), sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*str)
	{
		if (((*str != ' ' && (t_split(*str) == 0)) || quote) && *str)
		{
			list[i] = cut_word(str);
			if (!list[i])
				return (NULL);
			i++;
			while (((*str != ' ' && (t_split(*str) == 0)) || quote) && *str)
				str += iterate(&quote, *str);
		}
		stru->i = i;
		str = split_line_part2(list, str, stru);
		str = split_line_part3(str, &quote);
		i = stru->i;
	}
	list[i] = NULL;
	return (list);
}
