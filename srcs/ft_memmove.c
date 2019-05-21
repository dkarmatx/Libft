/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:43:42 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 21:41:49 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*buff;

	buff = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if (buff)
	{
		ft_memcpy(buff, src, n);
		ft_memcpy(dst, buff, n);
	}
	return (dst);
}
