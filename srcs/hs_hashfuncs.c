/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hs_hashfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:02:41 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 05:14:44 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashfuncs.h"

t_u64		hs_djb2_64(char const *str)
{
	t_u64	hash;

	hash = HS_DJB_OFFSET;
	while (*str)
		hash = ((hash << 5) + hash) + (t_u64)(*str++);
	return (hash);
}

t_u32		hs_fnv1a_32(char const *str)
{
	t_u32	hash;

	hash = HS_32_FNV_OFFSET;
	while (*str)
	{
		hash ^= *str++;
		hash *= HS_32_FNV_PRIME;
	}
	return (hash);
}

t_u64		hs_fnv1a_64(char const *str)
{
	t_u64	hash;

	hash = HS_64_FNV_OFFSET;
	while (*str)
	{
		hash ^= *str++;
		hash *= HS_64_FNV_PRIME;
	}
	return (hash);
}
