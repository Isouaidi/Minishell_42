/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:29:09 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/07 16:16:51 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

{
	t_list	*tmp;
	t_list	*nvlist;

	if (!lst)
		return (0);
	nvlist = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst ->content));
		if (!tmp)
		{
			ft_lstclear (&tmp, (*del));
			return (0);
		}
		ft_lstadd_back(&nvlist, tmp);
		lst = lst ->next;
	}
	return (nvlist);
}
