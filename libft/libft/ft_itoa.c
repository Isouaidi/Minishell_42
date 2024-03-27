/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:15:54 by isouaidi          #+#    #+#             */
/*   Updated: 2023/06/05 17:17:09 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count ++;
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nbr;
	char		*str;

	i = countnbr(n);
	nbr = n;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (nbr)
	{
		str[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (str);
}
