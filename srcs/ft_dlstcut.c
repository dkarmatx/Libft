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
	t_dlist				*prev;
	t_dlist				*next;

	prev = clst->prev;
	next = clst->next;
	if (!cutdlst || !(*cutdlst))
		return (0);
	if (!prev && !next)
	{
		*cutdlst = (t_dlist *)0;
		return ((t_dlist *)clst);
	}
	if (prev)
		prev->next = next;
	else
	{
		(*cutdlst) = next;
		(*cutdlst)->prev = 0;
	}
	if (next)
		next->prev = prev;
	return ((t_dlist *)clst);
}
