/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:14:26 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/17 17:15:00 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"

ssize_t			dstr_insert_ch(DSTRING *dst, char ch, ssize_t ind)
{
	DSTRING		*tmp;
	char		fake[2];

	fake[0] = ch;
	fake[1] = '\0';
	if (!(tmp = dstr_new(fake)))
		return (-1);
	if (!dst)
		return (-1);
	ind = dstr_insert_dstr(dst, tmp, ind);
	dstr_del(&tmp);
	return (ind);
}

ssize_t			dstr_insert_str(DSTRING *dst, char *src, ssize_t ind)
{
	DSTRING		*tmp;

	if (!src)
		return (ind);
	if (!(tmp = dstr_new(src)))
		return (-1);
	if (!dst)
		return (-1);
	ind = dstr_insert_dstr(dst, tmp, ind);
	dstr_del(&tmp);
	return (ind);
}

ssize_t			dstr_insert_dstr(DSTRING *dst, DSTRING *src, ssize_t ind)
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
