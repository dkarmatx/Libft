/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:41:18 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 21:40:48 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*s;
	unsigned long	*d;
	unsigned char	*sc;
	unsigned char	*dc;
	size_t			nb;

	d = (unsigned long *)dst;
	s = (unsigned long *)src;
	nb = n / sizeof(unsigned long);
	while (nb--)
		*(d++) = *(s++);
	nb = n % sizeof(unsigned long);
	sc = (unsigned char *)s;
	dc = (unsigned char *)d;
	while (nb--)
		*(dc++) = *(sc++);
	return (dst);
}
