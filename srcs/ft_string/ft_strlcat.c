/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 05:59:50 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:31:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"

size_t		ft_strlcat(char *dst, const char *src, size_t mxlen)
{
	size_t	src_len;
	size_t	dst_len;
	char	*cat_pos;
	size_t	inpt;

	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, mxlen);
	if (mxlen == 0)
		return (src_len);
	if (dst_len != mxlen)
	{
		inpt = mxlen - dst_len - 1;
		if (inpt > src_len)
			inpt = src_len;
		cat_pos = dst + dst_len;
		ft_memcpy(cat_pos, src, inpt);
		cat_pos[inpt] = 0;
	}
	return (dst_len + src_len);
}
