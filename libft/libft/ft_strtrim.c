/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:52:26 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/03 19:46:32 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = ft_strlen(s1);
	if (!set)
		return ((char *) s1);
	if (!s1)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == n)
	{
		str = ft_strdup("");
		return (str);
	}
	while (ft_strchr(set, s1[n - 1]) && i < n)
		n--;
	str = ft_substr(s1, i, n - i);
	return (str);
}
