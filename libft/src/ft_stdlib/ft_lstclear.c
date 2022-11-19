/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:17:12 by arobu             #+#    #+#             */
/*   Updated: 2022/10/20 19:09:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		tmp_lst = (*lst)-> next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp_lst;
	}
}
