/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:59:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 16:47:31 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*convert_env(t_env *env, t_stru *stru, t_pars *list)
{
	int		i;
	char	**splite;
	t_env	*tes;

	stru->check = 1;
	i = 0;
	tes = env;
	if (env == NULL)
	{
		env = malloc(sizeof(t_env));
		if (!env)
			return (NULL);
		tes = env;
		while (stru->env[i])
		{
			splite = env00(splite, *(&env), &i, stru);
			if (splite == NULL)
				return (NULL);
			env = env->next;
			i++;
		}
	}
	doll1(list, tes);
	return (tes);
}

char	*check_dol(char *recup, t_env *env)
{
	t_dol	dol;

	dol.i = 0;
	dol.quote = 0;
	dol.d = 0;
	dol.j = 0;
	while (recup[dol.i])
	{
		parse_before_dollar(recup, &dol);
		parse_after_dollar(recup, env, &dol);
		parse_after(recup, &dol);
	}
	return (ft_mostrjoin(dol.avant, dol.va, dol.apres));
}

void	doll1(t_pars *list, t_env *env)
{
	int		j;
	char	quote;

	j = 0;
	quote = 0;
	while (list)
	{
		j = 0;
		while (list->val[j])
		{
			quote = update_quote(quote, list->val[j]);
			if (list->val[j] == '$' && list->val[j + 1] == '?' && quote != '\'')
				list->val = modifintero(list->val, 0, 0);
			else if (list->val[j] == '$')
				list->val = check_dol(list->val, env);
			j++;
		}
		list = list->next;
	}
}

char	*check_dollars(char *str, t_env *env)
{
	char	*va;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va = ft_strdup("");
	while (env)
	{
		if (ft_strcmp(str, env->name) == 0)
		{
			va = malloc(sizeof(char) * ft_strlen(env->value + 1));
			while (env->value[i])
				va[j++] = env->value[i++];
			va[j] = '\0';
		}
		env = env->next;
	}
	return (va);
}
