/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:35:12 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/08 21:24:44 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env00(char **splite, t_env *env, int *i, t_stru *stru)
{
	splite = ft_split(stru->env[*i], '=');
	if (splite[0])
		env->name = ft_strdup(splite[0]);
	if (splite[1])
		env->value = ft_strdup(splite[1]);
	else
		env->value = NULL;
	free_tab(splite);
	if (stru->env[*i + 1] == NULL)
		env->next = NULL;
	else
	{
		env->next = malloc(sizeof(t_env));
		if (!env->next)
			return (NULL);
	}
	return (splite);
}

char	*parse_before_dollar(char *recup, int *i, char quote)
{
	int		j;
	char	*avant;

	avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	j = 0;
	while (recup[*i] && quote != '\'')
	{
		quote = update_quote(quote, recup[*i]);
		if (recup[*i] == '$')
			break ;
		avant[j++] = recup[(*i)++];
	}
	avant[j] = '\0';
	return (avant);
}

char	*parse_after_dollar(char *recup, int *i, t_env *env, char quote)
{
	char	*va;

	va = NULL;
	if (recup[*i] == '\0')
	{
		va = ft_strdup("");
		(*i)++;
	}
	else if (recup[*i] == '$' && recup[*i + 1] == '\0')
	{
		va = ft_strdup("$");
		(*i)++;
	}
	else if (recup[*i] == '$')
		va = extract_variable(recup, i, env, quote);
	return (va);
}

char	*extract_variable(char *recup, int *i, t_env *env, char quote)
{
	int		j;
	char	*va;
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	j = 0;
	(*i)++;
	while (recup[*i] && recup[*i] != '"' && recup[*i] != '\''
		&& recup[*i] != ' ' && recup[*i] != '$')
	{
		quote = update_quote(quote, recup[*i]);
		temp[j++] = recup[(*i)++];
	}
	temp[j] = '\0';
	va = check_dollars(temp, env);
	free(temp);
	return (va);
}

char	*parse_after(char *recup, int *i, char quote)
{
	int		j;
	char	*apres;

	j = 0;
	apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	while (recup[*i])
	{
		quote = update_quote(quote, recup[*i]);
		apres[j++] = recup[(*i)++];
	}
	apres[j] = '\0';
	return (apres);
}
