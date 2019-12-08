/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:43:42 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/08 21:18:34 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "libft_hidden.h"

static inline void		cpy_rbytes(t_byte *dst, t_byte *src, size_t n)
{
	while (n--)
		*(dst + n) = *(src + n);
}

static inline void		cpy_rwords(t_lword *dst, t_lword *src, size_t n)
{
	while (n--)
		*(dst + n) = *(src + n);
}

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	t_byte	*dst_b;
	t_byte	*src_b;
	size_t	tmp;

	dst_b = (t_byte *)dst;
	src_b = (t_byte *)src;
	if (dst_b == src_b)
		return (dst);
	if (len >= LWORD_SIZE)
	{
		tmp = ((size_t)dst + len) % LWORD_SIZE;
		cpy_rbytes(dst_b + len - tmp, src_b + len - tmp, tmp);
		len -= tmp;
		tmp = (LWORD_SIZE - ((size_t)dst % LWORD_SIZE)) % LWORD_SIZE;
		cpy_rwords((t_lword *)(dst + tmp), \
		(t_lword *)(src + tmp), len / LWORD_SIZE);
		len -= (len / LWORD_SIZE) * LWORD_SIZE;
	}
	cpy_rbytes(dst_b, src_b, len);
	return (dst);
}
