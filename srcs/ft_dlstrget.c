/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:33:53 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 14:35:57 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstrget(t_dlist *cdlst, size_t ind)
{
	while (ind-- && cdlst)
		cdlst = cdlst->prev;
	return (cdlst);
}
