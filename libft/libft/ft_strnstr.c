/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:23:31 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/07 14:38:18 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
/* s[i + j] car i avance jusqua le premier caractere de la seconde chaine 
et par la suite il se stop pour lire le mot dans la seconde avec j
pour quand il est return s1 il est return a partir de i et si J et j ne sont 
pas egal ruturn 0 */

/*int main()
{
char ss1[] = "hello my name is ilyes"; 

char ss2[] = "ilyes";

printf("%s",ft_strnstr(ss1, ss2 , 22));
}*/
