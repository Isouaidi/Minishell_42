/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:35:12 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/09 19:20:14 by isouaidi         ###   ########.fr       */
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

int	parse_before_dollar(char *recup, t_dol *dol)
{
	dol->avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	while (recup[dol->i] && dol->d != 1)
	{
		dol->quote = update_quote(dol->quote, recup[dol->i]);
		if (recup[dol->i] == '$' && dol->quote != '\'')
		{
			dol->d = 1;
			break ;
		}
		dol->avant[dol->j++] = recup[dol->i++];
	}
	dol->avant[dol->j] = '\0';
	return (0);
}

void	parse_after_dollar(char *recup, t_env *env, t_dol *dol)
{
	if (recup[dol->i] == '\0')
	{
		dol->va = ft_strdup("");
		dol->d = 1;
	}
	if (recup[dol->i] != '\0')
		dol->d = 0;
	dol->j = 0;
	if ((recup[dol->i] == '$' && recup[dol->i + 1] == '\0')
		|| (recup[dol->i + 1] == '"' && recup[dol->i] == '$'
			&& recup[dol->i + 1] == '"' ))
		dol->va = ft_strdup("$");
	else if (recup[dol->i] == '$' && dol->d == 0)
		extract_variable(recup, env, dol);
}

void	extract_variable(char *recup, t_env *env, t_dol *dol)
{
	dol->va = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	dol->i++;
	while (recup[dol->i] && recup[dol->i] != '"' && recup[dol->i] != '\''
		&& recup[dol->i] != ' ' && recup[dol->i] != '$')
	{
		dol->quote = update_quote(dol->quote, recup[dol->i]);
		dol->va[dol->j++] = recup[dol->i++];
	}
	dol->va[dol->j] = '\0';
	dol->va = check_dollars(dol->va, env);
}

void	parse_after(char *recup, t_dol *dol)
{
	dol->d = 0;
	dol->j = 0;
	dol->apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
	while (recup[dol->i])
	{
		dol->quote = update_quote(dol->quote, recup[dol->i]);
		dol->apres[dol->j++] = recup[dol->i++];
	}
	dol->apres[dol->j] = '\0';
	dol->quote = update_quote(dol->quote, recup[dol->i]);
}
