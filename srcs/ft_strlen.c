/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:52:59 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:31:40 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	get_len_zero_byte(const char *chp, const char *str)
{
	if (chp[0] == 0)
		return (chp - str);
	if (chp[1] == 0)
		return (chp - str + 1);
	if (chp[2] == 0)
		return (chp - str + 2);
	if (chp[3] == 0)
		return (chp - str + 3);
	if (chp[4] == 0)
		return (chp - str + 4);
	if (chp[5] == 0)
		return (chp - str + 5);
	if (chp[6] == 0)
		return (chp - str + 6);
	if (chp[7] == 0)
		return (chp - str + 7);
	return (0);
}

size_t			ft_strlen(const char *s)
{
	const unsigned long		*lp;
	const char				*chr;
	unsigned long			longc;

	chr = (const char *)s;
	while (((unsigned long)chr & (sizeof(longc) - 1)) != 0)
	{
		if (*chr == 0)
			return (chr - s);
		++chr;
	}
	lp = (const unsigned long *)(chr);
	while (1)
	{
		longc = *lp++;
		if (((longc - 0x0101010101010101) & ~longc & 0x8080808080808080) != 0)
		{
			chr = (const char *)(lp - 1);
			return (get_len_zero_byte(chr, s));
		}
	}
	return (0);
}
