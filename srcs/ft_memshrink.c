/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memshrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:33:57 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/17 08:03:58 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memshrink(void *src, void *dst, size_t offset, size_t len)
{
	if (dst)
		ft_memdel(&dst);
	if (src)
		if ((dst = ft_memdup(src + offset, len)))
			ft_memdel(&src);
	return (dst);
}
