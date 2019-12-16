/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 06:38:38 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:08:26 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hstb.h"
#include <stdlib.h>
#include "ft_mem.h"

t_htb_hid		*ht_b_alloca_std(size_t size)
{
	t_htb_hid	*table;

	if (size == 0)
		return (NULL);
	table = ft_memalloc(sizeof(t_htb_hid));
	if (table == NULL)
		return (NULL);
	table->magic = HS_MAGICWORD;
	table->heap = ft_memalloc(size * sizeof(t_kv));
	if (table->heap == NULL)
	{
		free(table);
		return (NULL);
	}
	table->heap_size = size;
	table->cleanf = NULL;
	table->elems_count = 0;
	table->hashf = hs_fnv1a_64;
	return (table);
}

t_ht_id			ht_create(
	t_free_callbk free_func,
	t_hash_fn hsfunc,
	size_t ini_size)
{
	t_htb_hid	*table;

	if (NULL == (table = ht_b_alloca_std(ini_size)))
		return (NULL);
	hsfunc != NULL ? table->hashf = hsfunc : 0;
	free_func != NULL ? table->cleanf = free_func : 0;
	return ((t_ht_id)table);
}

t_htb_hid		*ht_b_isid(t_ht_id id)
{
	t_htb_hid	*table;

	if (NULL == id)
		return (NULL);
	table = (t_htb_hid *)id;
	if (table->magic == HS_MAGICWORD)
		return (table);
	return (NULL);
}

void			ht_free(t_ht_id htid)
{
	t_htb_hid	*table;
	size_t		i;

	if (!(table = ht_b_isid(htid)))
		return ;
	i = -1;
	while (++i < table->heap_size)
	{
		if (table->heap[i].key)
		{
			if (table->cleanf)
				table->cleanf(table->heap[i].val);
			free(table->heap[i].key);
			table->heap[i].key = 0;
			table->heap[i].val = 0;
		}
	}
	free(table->heap);
	table->magic = 0;
	free(table);
}

int				ht_addsafe(t_ht_id htid, char *const key, \
void *ptr, size_t size)
{
	void		*new_val;
	int			status;

	if (!ht_b_isid(htid) || !key || !size)
		return (HT_BADACCESS);
	if (!(new_val = ft_memdup(ptr, size)))
		return (HT_ALLOCAFAIL);
	if ((status = ht_addptr(htid, key, new_val, 1)) == HT_ALLOCAFAIL)
	{
		free(new_val);
		return (HT_ALLOCAFAIL);
	}
	else if (status == HT_ALREXIST)
	{
		free(new_val);
		return (HT_ALREXIST);
	}
	return (status);
}
