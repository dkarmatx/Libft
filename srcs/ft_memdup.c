/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:29:18 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/23 21:52:52 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(void *start, size_t len)
{
	void	*newmem;

	if (!len)
		return (0);
	if ((newmem = malloc(len)))
		ft_memcpy(newmem, start, len);
	return (newmem);
}
