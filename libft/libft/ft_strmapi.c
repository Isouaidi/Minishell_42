/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:35:29 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/04 18:56:16 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*scpy;

	i = 0;
	scpy = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!scpy)
		return (0);
	while (i < ft_strlen(s))
	{
		scpy[i] = f(i, s[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
