/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:24:16 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/05 21:24:17 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *abc;

	abc = NULL;
	if (!lst || !f)
		return (NULL);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
	{
		free(list);
		return (NULL);
	}
	list = (*f)(lst);
	abc = list;
	while (lst->next != NULL)
	{
		list->next = (*f)(lst->next);
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (abc);
}
