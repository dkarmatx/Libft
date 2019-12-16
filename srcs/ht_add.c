/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 07:17:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:08:52 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hstb.h"
#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"

t_i64			ht_b_geths(t_htb_hid *tb, char const *str)
{
	t_u64		i;
	t_u64		h1;
	t_i64		h;

	i = 0;
	if (tb->elems_count >= (tb->heap_size + tb->heap_size / 2) / 2)
		return (HT_OVER);
	h1 = tb->hashf(str);
	while (i < tb->heap_size)
	{
		h = 0x7fffffffffffffff & ((h1 + i) % tb->heap_size);
		if (tb->heap[h].key == NULL)
			return (h);
		else if (ft_strequ(tb->heap[h].key, str))
			return (h);
		++i;
	}
	return (HT_OVER);
}

t_i64			ht_b_getindex(t_htb_hid *tb, char const *str)
{
	t_i64		h;

	h = ht_b_geths(tb, str);
	if (h == HT_OVER)
		return (HT_OVER);
	if (tb->heap[h].key != NULL)
		return (HT_EXISTS);
	return (h);
}

int				ht_b_swap(t_htb_hid *tb, char const *key, void *p)
{
	t_kv		*kv;
	t_i64		index;

	index = ht_b_geths(tb, key);
	kv = &(tb->heap[index]);
	if (tb->cleanf)
		tb->cleanf(kv->val);
	kv->val = p;
	return (HT_OK);
}

int				ht_addptr(t_ht_id htid, char *const key, void *ptr, int sv)
{
	t_htb_hid	*table;
	t_i64		index;
	t_u64		i;
	t_kv		kv;

	i = 0;
	if (!(table = ht_b_isid(htid)) && !key)
		return (HT_BADACCESS);
	index = ht_b_getindex(table, key);
	if (index == HT_OVER)
	{
		ht_b_heap_resize(table);
		index = ht_b_getindex(table, key);
	}
	else if (index == HT_EXISTS && !sv)
		return (ht_b_swap(table, key, ptr));
	else if (index == HT_EXISTS && sv)
		return (HT_ALREXIST);
	if (index == HT_EXISTS || index == HT_OVER || \
	!(kv.key = ft_strdup(key)))
		return (HT_ALLOCAFAIL);
	kv.val = ptr;
	table->heap[index] = kv;
	table->elems_count++;
	return (HT_OK);
}

int				ht_add(t_ht_id htid, char *const key, \
void *ptr, size_t size)
{
	void		*new_val;
	int			status;

	if (!ht_b_isid(htid) || !key || !size)
		return (HT_BADACCESS);
	if (!(new_val = ft_memdup(ptr, size)))
		return (HT_ALLOCAFAIL);
	if ((status = ht_addptr(htid, key, new_val, 0)) == HT_ALLOCAFAIL)
	{
		free(new_val);
		return (HT_ALLOCAFAIL);
	}
	return (status);
}
