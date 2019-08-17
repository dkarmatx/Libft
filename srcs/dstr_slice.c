/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:15:19 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/17 17:15:36 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"

DSTRING			*dstr_slice(DSTRING *src, ssize_t bi, ssize_t ei)
{
	DSTRING		*dstr;
	ssize_t		ri[2];

	ri[0] = (bi < 0) ? (src->strlen) + bi : bi;
	ri[1] = (ei < 0) ? (src->strlen) + ei : ei;
	ri[0] = (ri[0] < 0) ? 0 : ri[0];
	ri[1] = (ri[1] < 0) ? 0 : ri[1];
	ri[0] = (ri[0] > src->strlen) ? src->strlen : ri[0];
	ri[1] = (ri[1] > src->strlen) ? src->strlen : ri[1];
	if (ri[0] >= ri[1])
		return (dstr_new(""));
	if (!(dstr = dstr_new(0)))
		return (0);
	dstr->strlen = ri[1] - ri[0];
	dstr->bks = (dstr->strlen / DSTR_BLK_SZ) + 1;
	if (!(dstr->txt = ft_memalloc(dstr->bks * DSTR_BLK_SZ)))
	{
		free(dstr);
		return (0);
	}
	ft_memcpy(dstr->txt, &(src->txt[ri[0]]), dstr->strlen);
	return (dstr);
}
