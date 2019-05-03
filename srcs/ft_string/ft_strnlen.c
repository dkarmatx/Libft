/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:04:42 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:33:03 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t		i;

	i = 0;
	if (s)
		i = ft_strlen(s);
	i > maxlen ? (i = maxlen) : i;
	return (i);
}
