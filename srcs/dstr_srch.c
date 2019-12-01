/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_srch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:10:25 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/01 16:13:44 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"

size_t			dstr_search_ch(const DSTRING *src, const char ch, size_t offs)
{
	char		*ch_ptr;
	size_t		ind;

	if (!ch || !src)
		return (SIZE_T_MAX);
	if (offs >= (size_t)src->strlen)
		return (SIZE_T_MAX);
	ch_ptr = (char *)ft_memchr(src->txt + offs, (int)ch, (size_t)src->strlen);
	if (ch_ptr == 0)
		return (SIZE_T_MAX);
	ind = (size_t)ch_ptr - (size_t)src->txt;
	return (ind);
}

size_t			dstr_search_str(const DSTRING *src, \
const char *str, size_t offset)
{
	char		*str_ptr;
	size_t		ind;

	if (!str || !src)
		return (SIZE_T_MAX);
	if (offset > (size_t)(src->strlen + ft_strlen(str)))
		return (SIZE_T_MAX);
	str_ptr = (char *)ft_mem_mem(src->txt + offset, str, src->strlen, \
	ft_strlen(str));
	if (str_ptr == 0)
		return (SIZE_T_MAX);
	ind = (size_t)str_ptr - (size_t)src->txt;
	return (ind);
}

size_t			dstr_search_dstr(const DSTRING *src, \
const DSTRING *d, size_t offset)
{
	char		*str_ptr;
	size_t		ind;

	if (!d || !src)
		return (SIZE_T_MAX);
	if (offset > (size_t)(src->strlen + d->strlen))
		return (SIZE_T_MAX);
	str_ptr = (char *)ft_mem_mem(src->txt + offset, d->txt, \
	src->strlen, d->strlen);
	if (str_ptr == 0)
		return (SIZE_T_MAX);
	ind = (size_t)str_ptr - (size_t)src->txt;
	return (ind);
}
