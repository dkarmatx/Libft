/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:46:22 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:30:15 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (dst);
}
