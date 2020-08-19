/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:27:29 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:29:05 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lst_add_back(t_lst **alst, t_lst *new)
{
	t_lst *tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_lst	*lstnew(t_coord *el, int ne)
{
	t_lst *list;

	if (!(list = (t_lst*)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	if (!el)
	{
		list->coord = NULL;
		list->ne = 0;
	}
	else
	{
		list->coord = el;
		list->ne = ne;
	}
	list->next = NULL;
	return (list);
}
