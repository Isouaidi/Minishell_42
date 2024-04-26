/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:42:58 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/22 18:12:09 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	supquote(t_parser *list)
{
	while (list)
	{
		delete(list->val);
		list = list->next;
	}
}

void    take_more(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        str[i] = str[i + 1];
        i++;
    }
}
void    in_quote(char *quote, char cur)
{
    if (cur == '"' || cur == '\'')
    {
        if (*quote == 0)
            *quote = cur;
        else if (*quote == cur)
            *quote = 0;
    }
}

void    delete(char *str)
{
    int     i;
    char    quote;

    i = 0;
    quote = 0;
    while (str && str[i])
    {
        in_quote(&quote, str[i]);
        if (!quote)
            i++;
        else if (str[i])
        {
            take_more(str + i);
            while (quote && str[i])
            {
                in_quote(&quote, str[i]);
                if (quote)
                    i++;
            }
            take_more(str + i);
        }
    }
}

