/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:40:42 by isouaidi          #+#    #+#             */
/*   Updated: 2024/04/16 17:42:58 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char	*s1, const char	*s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - ((unsigned char)s2[i]));
		i++;
	}
	return (0);
}
/*int main()
{
	printf("%d",strncmp("hello", "bonjour",5));
	printf("resul:%d\n", ft_strncmp("hello","bonjour", 5));
	return(0);
}*/
