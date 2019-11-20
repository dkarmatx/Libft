/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:33:59 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:14:52 by hgranule         ###   ########.fr       */
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
			return (++count);
	}
	return (0);
}

void			*ft_mem_mem(const void *src, const void *sbmem, \
size_t len, const size_t sblen)
{
	unsigned char	*its;
	size_t			reslen;
	size_t			chk_cnt;
	const void		*end_of_src = src + (len - 1);

	if (!src || !sbmem || !sblen)
		return (0);
	its = (unsigned char *)src;
	reslen = (((size_t)end_of_src - (size_t)its) - sblen) + 2;
	while ((its = ft_memchr(\
		its, \
		*((unsigned char *)sbmem), \
		reslen)) != 0)
	{
		if (!(chk_cnt = ft_memcmp_bltn(its, sbmem, sblen)))
			return ((void *)its);
		its = its + chk_cnt;
		reslen = (((size_t)end_of_src - (size_t)its) - sblen) + 2;
	}
	return (0);
}
