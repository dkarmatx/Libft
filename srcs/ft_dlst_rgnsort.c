/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_rgnsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:04:30 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 14:25:33 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlst_rgnsort(t_dlist **list, int (*f)(void *, void *))
{
	t_dlist		*clist;
	t_dlist		*plist;

	if (!list || !(*list) || !((*list)->next))
		return ;
	plist = (*list)->next;
	clist = plist->next;
	while (plist)
	{
		if (!plist->prev || ((*f)(plist->prev->content, plist->content) > 0))
		{
			plist = clist;
			(clist ? clist = clist->next : clist);
		}
		else
		{
			ft_dlstswap(plist->prev, plist);
			plist = plist->prev;
			if (plist == 0)
			{
				plist = clist;
				(clist ? clist = clist->next : clist);
			}
		}
	}
}
