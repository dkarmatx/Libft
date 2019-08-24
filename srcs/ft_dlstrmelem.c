/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrmelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:45:42 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/24 07:10:29 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

void	ft_dlstrmelem(t_dlist **deldlst)
{
	t_dlist		*removed;

	if (!deldlst || !(*deldlst))
		return ;
	removed = ft_dlstcut(deldlst);
	if (removed->size && removed->content)
		free(removed->content);
	free(removed);
}

void	ft_dlst_delcut(t_dlist **deldlst, void (*rmfunc)(void *))
{
	t_dlist		*removed;

	if (!deldlst || !(*deldlst))
		return ;
	removed = ft_dlstcut(deldlst);
	rmfunc(removed->content);
	free(removed);
}
