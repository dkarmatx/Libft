/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:31:05 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 08:41:08 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstshift(t_dlist **list)
{
	t_dlist		*lst;

	if (!list || !(*list))
		return (0);
	if ((lst = *list)->next)
	{
		*list = lst->next;
		lst->next->prev = 0;
	}
	return (lst);
}
