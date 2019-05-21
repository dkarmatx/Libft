/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:17:53 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 15:34:50 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

void	ft_dlstdel(t_dlist **dlst, size_t n)
{
	t_dlist		*tmp;

	if (!dlst || !(*dlst))
		return ;
	while ((tmp = *dlst) && n--)
	{
		if (tmp->content && tmp->size)
			free(tmp->content);
		(*dlst) = (*dlst)->next;
		if (*dlst)
			(*dlst)->prev = 0;
		free(tmp);
	}
}
