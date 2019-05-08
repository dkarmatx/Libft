/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:53:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/08 16:26:28 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstcut(t_dlist **cutdlst)
{
	const t_dlist		*clst = (*cutdlst);

	if (!cutdlst || !(*cutdlst))
		return (0);
	if (!((*cutdlst)->prev) && !((*cutdlst)->next))
	{
		*cutdlst = (t_dlist *)0;
		return ((t_dlist *)clst);
	}
	if ((*cutdlst)->prev)
		(*cutdlst)->prev->next = (*cutdlst)->next;
	else
	{
		(*cutdlst) = (*cutdlst)->next;
		(*cutdlst)->prev = 0;
	}
	if ((*cutdlst)->next)
		(*cutdlst)->next->prev = (*cutdlst)->prev;
	return ((t_dlist *)clst);
}
