/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:53:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 15:14:54 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstcut(t_dlist *cutdlst)
{
	t_dlist		*prev;
	t_dlist		*next;

	if (!cutdlst)
		return (0);
	prev = cutdlst->prev;
	next = cutdlst->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return (cutdlst);
}
