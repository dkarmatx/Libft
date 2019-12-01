/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:33:59 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/01 16:12:14 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

static size_t	ft_memcmp_bltn(const void *m1, const void *m2, size_t len)
{
	size_t			count;
	unsigned char	*ucm1;
	unsigned char	*ucm2;

	ucm1 = (unsigned char *)m1;
	ucm2 = (unsigned char *)m2;
	count = 0;
	while (len--)
	{
		if (ucm1[count] == ucm2[count])
			++count;
		else
			return (count);
	}
	return (0);
}

void			*ft_mem_mem(const void *src, const void *sbmem, \
size_t len, const size_t sblen)
{
	void			*its;
	size_t			reslen;
	size_t			chk_cnt;
	const void		*end_of_srch = (void *)((void *)(src + len) - sblen);

	if (!src || !sbmem || !sblen || len < sblen)
		return (0);
	reslen = len - sblen + 1;
	its = (unsigned char *)src;
	while ((its = ft_memchr(\
		its, \
		*((unsigned char *)sbmem), \
		reslen)) != 0)
	{
		if (!(chk_cnt = ft_memcmp_bltn(its, sbmem, sblen)))
			return ((void *)its);
		its = its + chk_cnt;
		reslen = end_of_srch - its + 1;
	}
	return (0);
}
