/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:02:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:32:33 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		src_len;

	src_len = ft_strlen(src);
	if (len)
	{
		if (src_len < len)
		{
			ft_memcpy(dst, src, src_len);
			ft_bzero(dst + src_len, len - src_len);
		}
		else
		{
			ft_memcpy(dst, src, len);
		}
	}
	return (dst);
}
