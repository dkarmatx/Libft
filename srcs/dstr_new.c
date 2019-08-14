/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:46:00 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/14 19:54:29 by hgranule         ###   ########.fr       */
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
		return (dstr_new(0));
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

ssize_t			dstr_insert_str(DSTRING *dst, DSTRING *src, ssize_t ind)
{
	const ssize_t		nlen = src->strlen + dst->strlen;
	const ssize_t		nbks = (nlen / DSTR_BLK_SZ) + 1;
	char				*ntxt;

	if (nlen <= 0)
		return (0);
	if (ind < 0)
		ind = 0;
	else if (ind > dst->strlen)
		ind = dst->strlen;
	if (!(ntxt = ft_memalloc(nbks * DSTR_BLK_SZ)))
		return (-1);
	ft_memcpy(ntxt, dst->txt, ind);
	ft_memcpy(&(ntxt[ind]), src->txt, src->strlen);
	ft_memcpy(&(ntxt[src->strlen + ind]), &(dst->txt[ind]), dst->strlen - ind);
	free(dst->txt);
	dst->txt = ntxt;
	dst->strlen = nlen;
	dst->bks = nbks;
	return (ind + src->strlen);
}

DSTRING			*dstr_new(const char *src)
{
	DSTRING		*dstr;

	if (!(dstr = ft_memalloc(sizeof(DSTRING))))
		return (0);
	if (!src)
		return (dstr);
	dstr->strlen = ft_strlen(src);
	dstr->bks = (dstr->strlen / DSTR_BLK_SZ) + 1;
	if (!(dstr->txt = ft_memalloc(dstr->bks * DSTR_BLK_SZ)))
	{
		free(dstr);
		return (0);
	}
	ft_memcpy(dstr->txt, src, (size_t)dstr->strlen);
	return (dstr);
}
