/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:59:10 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/20 15:36:09 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char	**env)
{
	while (*env)
	{
	 	printf("%s\n", *env);
		env++;
	}
		
}
void	convert_env(t_env *env, t_stru *stru, t_parser *list)
{
	int i;
	int j;
	char **split;
	t_env *tes;

	i = 0;
	env = malloc(sizeof(t_env));
	tes = env;
	while (stru->env[i])
	{
		j = 0;
		split = ft_split(stru->env[i], '=');
		j = ft_strlen(split[0]);
		env->name = malloc(sizeof(char) * (j + 1));
		env->name = split[0];
		if (split[1] != NULL)
			j = ft_strlen(split[1]);
		env->value = malloc(sizeof(char) * (j + 1));
		env->value = split[1];
		if (stru->env[i + 1] == NULL)
			env->next = NULL;
		else
			env->next = malloc(sizeof(t_env));
		free(split);
		env = env->next;
		i++;
	}
	i = 0;
	//chaine_env (tes);
	doll1(list, *(&tes));
}

void	chaine_env(t_env *en)
{
	int i; 

	i = 0;
	while (en)
	{
		printf("name[%d] = %s\n",i, en->name);
		printf("value[%d] = %s\n\n",i, en->value);
		i++;
		en = en->next;
	} 	
}
// char *check_dol(char *recup, t_env *env)
// {   
//     int i = 0;
//     int j = 0;
//     char quote = 0;
//     char *str;
//     char *avant;
//     char *va;
//     char *apres;

//     while (recup[i])
//     {
//         avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//         while (recup[i] != '$' && recup[i])
//         {
//             quote = update_quote(quote, recup[i]);
//             avant[j++] = recup[i++];        
//         }
// 		// if (quote == '\'' )
// 		// 	avant[j++] = '$';
//         avant[j] = '\0';
//         j = 0;
//         if (recup[i] == '$')
//         {
//             i++;
//             va = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//             while (recup[i] && recup[i] != '"' && recup[i] != '\'' && recup[i] != ' ' && recup[i] != '$')
//             {
//                 quote = update_quote(quote, recup[i]);
//                 va[j++] = recup[i++];
//             }
//             va[j] = '\0';
//             va = check_dollars(va, env, quote);
//         }

//         j = 0;
//         apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//         while (recup[i])
//         {
//             quote = update_quote(quote, recup[i]);
//             apres[j++] = recup[i++];
//         }
//         apres[j] = '\0';

//         quote = update_quote(quote, recup[i]);
//     }

//     str = ft_mostrjoin(avant, va, apres);
//     return str;
// }

char *check_dol(char *recup, t_env *env)
{	
	int i;
	int j;
	char quote = 0;
	char *str;
	char *apres;
	char *avant;
	char *va;

	j = 0;
	i = 0;
	while (recup[i])
	{
		//avant = ft_strdup("");
		avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
		while (recup[i] != '$' && recup[i])
		{
			quote = update_quote(quote, recup[i]);
			printf("quote avan [i = %d] == %c\n", i , quote);
			avant[j++] = recup[i++];		
		}
		avant[j] = '\0';
		
		//printf("quote 0 %c [%d]\n",quote, i);
		//printf("print AVANT [%d] = %s\n",i ,avant);
		j = 0;
		if(recup[i] == '$')
		{
			printf("va [%d] = %c\n", i , recup[i]);
			printf("quote VA [i = %d] == %c\n", i , quote);
			//va = ft_strdup("");
			va = malloc(sizeof(char) * (ft_strlen(recup + 1)));
			i++;
			if (quote == '\'')
			{
				va[j++] = '\'';
				//break;
			}
			while (recup[i] && recup[i] != '"' && recup[i] != '\'' && recup[i] != ' ' && recup[i] != '$')
				{
					quote = update_quote(quote, recup[i]);
					printf("va avec [%d] = %c\n", i , recup[i]);
					printf("quote va avec [i = %d] == %c\n", i , quote);
					va[j++] = recup[i++];
				}
				va[j] = '\0';
				//printf("va avant [%d] = %s\n",i, va);
					va = check_dollars(va, env, quote);
			//printf("va apres [%d]= %s\n",i, va);
		}
			j = 0;
			apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
			while (recup[i])
			{
				quote = update_quote(quote, recup[i]);
				printf("quote apres [i = %d] == %c\n", i , quote);
				apres[j++] = recup[i++];
			}
			apres[j] = '\0';
			quote = update_quote(quote, recup[i]);
			//break;
			//printf("print APRES [%d] = %s\n\n",i, apres);
	}
	printf("---------------------------\n");
	printf("print avant = %s\n", avant);
	printf("print va = %s\n", va);
	printf("print apres = %s\n\n", apres);
	//free(recup);
	str = ft_mostrjoin(avant, va, apres);
	//free(avant);
	//free(apres);
	//if (va)
		//free(va);
	//printf("print complete = %s\n\n", str);
	return(str);
}

// char *check_dol(char *recup, t_env *env)
// {   
//     int i;
//     int j;
//     char quote = 0;
//     char *str;
//     char *apres;
//     char *avant;
//     char *va;

//     j = 0;
//     i = 0;
//     while (recup[i])
//     {
//         avant = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//         while (recup[i] != '$' && recup[i])
//         {
//             avant[j++] = recup[i++];
//         }
//         avant[j] = '\0';
        
//         j = 0;
//         if(recup[i] == '$' && quote != '\'')
//         {
//             i++;
//             va = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//             while (recup[i] && recup[i] != '"' && recup[i] != ' ' && recup[i] != '$')
//             {
//                 quote = update_quote(quote, recup[i]); // Mise à jour de quote
//                 va[j++] = recup[i++];
//             }
//             va[j] = '\0';

//             if (quote != '\'') // Si ce n'est pas une quote simple
//             {
//                 char *temp = va;
//                 va = check_dollars(va, env); // Appliquer la fonction récursive
//                 free(temp);
//             }
//         }
        
//         j = 0;
//         apres = malloc(sizeof(char) * (ft_strlen(recup + 1)));
//         while (recup[i])
//             apres[j++] = recup[i++];
//         apres[j] = '\0';
        
//         // Construction de la chaîne avec ou sans remplacement
//         str = ft_mostrjoin(avant, va ? va : "", apres);
//         free(avant);
//         free(apres);
//         free(va);
//         return str;
//     }
// }




void	doll1(t_parser *list, t_env *env)
{
	//int f = 0;
	int j = 0;
	char quote = 0;
	while (list)
	{
	//	f = 0;
		j = 0;
		while (list->val[j])
		{
			//f = 0;
			//j = 0;
			//while (list->val[j] && f != 1)
			//{
				quote = update_quote(quote, list->val[j]);
				if (list->val[j] == '$')
				{	
					list->val = check_dol(list->val, env);
			//		f = 1;
				//	break;
				}	
				j++;
			//}
			// if (f == 1)
			// {
			// 	//printf("list === %s\n", list->val);
			// }
		}
		list = list->next;
	}
		
}
char	*check_dollars(char *str, t_env *env, char quote)
{
	char *va;
	int i;
	int j;

	i = 0;
	j = 0;
	if (quote == '\'')
		return(str);
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
	return(va);
}
