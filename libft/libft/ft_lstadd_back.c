/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:03:23 by isouaidi          #+#    #+#             */
/*   Updated: 2023/11/22 00:19:03 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stacki **lst, t_stacki *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last ->next = new;
	}
	else
		*lst = new;
}
