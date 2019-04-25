/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 00:41:22 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/23 21:53:29 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcut(void *dst, void *src, size_t n, int filler)
{
	unsigned char	*buff;

	if (!n)
		return (0);
	buff = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if (buff)
	{
		ft_memcpy(buff, src, n);
		ft_memset(src, filler, n);
		ft_memcpy(dst, buff, n);
	}
	return (dst);
}
