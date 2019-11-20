/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:15:19 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:26:49 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"

static void		dstr_b_indexes(DSTRING *src, ssize_t bi, \
ssize_t ei, ssize_t *ri)
{
	ri[0] = (bi < 0) ? (src->strlen) + bi : bi;
	ri[1] = (ei < 0) ? (src->strlen) + ei : ei;
	ri[0] = (ri[0] < 0) ? 0 : ri[0];
	ri[1] = (ri[1] < 0) ? 0 : ri[1];
	ri[0] = (ri[0] > src->strlen) ? src->strlen : ri[0];
	ri[1] = (ri[1] > src->strlen) ? src->strlen : ri[1];
}

DSTRING			*dstr_slice(DSTRING *src, ssize_t bi, ssize_t ei)
{
	DSTRING		*dstr;
	ssize_t		ri[2];

	dstr_b_indexes(src, bi, ei, ri);
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

DSTRING			*dstr_slice_cut(DSTRING **src, ssize_t bi, ssize_t ei)
{
	DSTRING		*dstr_sl;
	DSTRING		*dstr_deld;
	DSTRING		*dstr_ol[2];
	ssize_t		ri[4];

	dstr_b_indexes(*src, bi, ei, ri);
	if (ri[0] >= ri[1])
		return (dstr_new(""));
	ri[2] = 0;
	ri[3] = (*src)->strlen;
	dstr_ol[0] = dstr_slice(*src, ri[2], ri[0]);
	dstr_ol[1] = dstr_slice(*src, ri[1], ri[3]);
	dstr_sl = dstr_slice(*src, ri[0], ri[1]);
	if (!dstr_ol[0] || !dstr_sl || !dstr_ol[1])
		return (0);
	dstr_del(src);
	*src = dstr_ol[0];
	dstr_deld = dstr_ol[1];
	if ((dstr_insert_dstr(*src, dstr_ol[1], SSIZE_T_MAX)) < 0)
		return (0);
	dstr_del(&dstr_deld);
	return (dstr_sl);
}

int				dstr_slice_del(DSTRING **src, ssize_t bi, ssize_t ei)
{
	DSTRING	*cutted;

	if (!src || !(*src))
		return (-1);
	cutted = dstr_slice_cut(src, bi, ei);
	if (!cutted)
		return (-2);
	dstr_del(&cutted);
	return (0);
}
