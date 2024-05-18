/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:17:27 by isouaidi          #+#    #+#             */
/*   Updated: 2024/05/18 16:34:52 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_sorted(t_env **env, t_env *newenv)
{
	t_env	*current;

	if (*env == NULL || ft_strcmp((*env)->name, newenv->name) >= 0)
	{
		newenv->next = *env;
		*env = newenv;
	}
	else
	{
		current = *env;
		while (current->next
			&& ft_strcmp(current->next->name, newenv->name) < 0)
			current = current->next;
		newenv->next = current->next;
		current->next = newenv;
	}
}

t_env	*sorted_insertion(t_env **env)
{
	t_env	*sorted;
	t_env	*current;
	t_env	*next;

	sorted = NULL;
	current = *env;
	while (current)
	{
		next = current->next;
		insert_sorted(&sorted, current);
		current = next;
	}
	*env = sorted;
	return (*env);
}

void	export_solo(t_env *env)
{
	t_env	*tmp;
	t_env	*sort;

	tmp = env;
	sort = sorted_insertion(&tmp);
	while (sort)
	{
		printf("declare -x ");
		if (sort->name)
		{
			if (ft_strcmp(sort->value, "") != 0)
				printf("%s=\"%s\"\n", sort->name, sort->value);
			else if (ft_strcmp(sort->value, "=") == 0)
				printf("%s\"%s\"\n", sort->name, sort->value);
			else if (ft_strcmp(sort->value, "") == 0)
				printf("%s\n", sort->name);
		}
		sort = sort->next;
	}
}

char	**equal(int c, int *i, t_cmd *cmd)
{
	char	**export;

	c = 0;
	export = ft_split(cmd->val[*i], '=');
	while (cmd->val[*i][c])
	{
		if (cmd->val[*i][c] == '=' && cmd->val[*i][c + 1] == '\0')
		{
			export[0] = ft_strdup(cmd->val[*i]);
			export[1] = ft_strdup("");
		}
		c++;
	}
	return (export);
}

int	export(t_stru *stru, t_cmd *cmd, int i, int j)
{
	char	**export;
	t_env	*tmp;

	tmp = stru->enuv;
	j = tablen(cmd->val);
	if (j == 1)
	{
		stru->cpoy_env = copy_list(tmp);
		export_solo(stru->cpoy_env);
	}
	while (cmd->val[i] && j > 1)
	{
		if (ft_strchr(cmd->val[i], '=') != NULL)
			export = equal(0, &i, cmd);
		else
		{
			export = ft_split(cmd->val[i], '=');
			export[0] = ft_strdup(cmd->val[i]);
			export[1] = ft_strdup("");
		}
		push_back_list(stru, export[0], export[1], 0);
		i++;
	}
	return(0);
}
