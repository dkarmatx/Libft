/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:05:59 by hgranule          #+#    #+#             */
/*   Updated: 2019/07/08 02:25:09 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s)
	{
		substr = (char *)malloc(sizeof(char) * (len + 1));
		if (substr)
		{
			ft_memcpy(substr, (s + start), len);
			substr[len] = 0;
			return (substr);
		}
	}
	return (0);
}
