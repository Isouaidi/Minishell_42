/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:27:06 by isouaidi          #+#    #+#             */
/*   Updated: 2023/11/22 00:19:26 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stacki	*ft_lstnew(void *content)
{
	t_stacki	*dst;

	dst = malloc(sizeof(t_stack));
	if (!dst)
		return (0);
	dst -> next = 0;
	dst -> content = content;
	return (dst);
}
