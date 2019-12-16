/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_getdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:21:49 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:04:07 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hstb.h"
#include <stdlib.h>

void			*ht_get(t_ht_id htid, char *const key)
{
	t_i64		h;
	t_htb_hid	*table;

	if (!(table = ht_b_isid(htid)) && !key)
		return (NULL);
	h = ht_b_geths(table, key);
	if (h == HT_OVER || h == HT_LOCKED)
		return (NULL);
	if (table->heap[h].key == NULL)
		return (NULL);
	return (table->heap[h].val);
}

void			*ht_cut(t_ht_id htid, char *const key)
{
	t_i64		h;
	t_htb_hid	*table;
	void		*ptr;

	if (!(table = ht_b_isid(htid)) && !key)
		return (NULL);
	h = ht_b_geths(table, key);
	if (h == HT_OVER || h == HT_LOCKED)
		return (NULL);
	if (table->heap[h].key == NULL)
		return (NULL);
	free(table->heap[h].key);
	ptr = table->heap[h].val;
	table->heap[h].key = NULL;
	table->heap[h].val = NULL;
	table->elems_count--;
	return (ptr);
}

void			ht_rm(t_ht_id htid, char *const key)
{
	t_i64		h;
	t_htb_hid	*table;

	if (!(table = ht_b_isid(htid)) && !key)
		return ;
	h = ht_b_geths(table, key);
	if (h == HT_OVER || h == HT_LOCKED)
		return ;
	if (table->heap[h].key == NULL)
		return ;
	free(table->heap[h].key);
	if (table->cleanf)
		table->cleanf(table->heap[h].val);
	table->heap[h].key = NULL;
	table->heap[h].val = NULL;
	table->elems_count--;
}
