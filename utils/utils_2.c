/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:52:38 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/18 14:05:00 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	erreurs(t_stru *stru)
{
	if (stru->er_pipe > 0)
		return (1);
	if (stru->er_tok > 0)
		return (2);
	return (0);
}

int	print_erreur(t_stru *stru)
{
	if (erreurs(stru) == 1)
	{
		printf("check your pipes\n");
		return (1);
	}
	if (erreurs(stru) == 2)
	{
		printf("check your tokkens\n");
		return (1);
	}
	return (0);
}
void	pipe_end(t_stru *stru, t_parser *list)
{
	while (list->next != NULL)
		list = list->next;
	printf("val = %s\n", list->val);
	printf("val = %d\n", list->tokken);
	if (list->tokken == 1 && list->next->val == NULL)
		stru->er_pipe = 1;
}
char	*ft_mostrjoin(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		c;
	int		j = 0;
	char	*result;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		result[i] = s2[c];
		i++;
		c++;
	}
	while (s3[j])
	{
		result[i] = s3[j];
		i++;
		j++;
	}
	
	result[i] = '\0';
	return (result);
}
