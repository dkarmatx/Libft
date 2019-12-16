/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 09:15:49 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:09:01 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hstb.h"
#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"

int					ht_b_heap_resize(t_htb_hid *tb)
{
	t_kv			*arr;
	size_t			i;
	t_i64			ind;

	arr = tb->heap;
	if (!(tb->heap = ft_memalloc(tb->heap_size * 2 * sizeof(t_kv))))
	{
		tb->heap = arr;
		return (-HT_ALLOCAFAIL);
	}
	i = 0;
	tb->heap_size *= 2;
	tb->elems_count = 0;
	while (i < (tb->heap_size / 2))
	{
		if (arr[i].key != NULL)
		{
			ind = ht_b_geths(tb, arr[i].key);
			ft_memcpy(tb->heap + ind, arr + i, sizeof(t_kv));
			tb->elems_count += 1;
		}
		++i;
	}
	free(arr);
	return (HT_OK);
}
