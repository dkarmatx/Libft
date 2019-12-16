/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:37:49 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:09:10 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hstb.h"

t_i64	ht_count(t_ht_id id)
{
	t_htb_hid	*table;

	if (!(table = ht_b_isid(id)))
		return (-HT_BADACCESS);
	return ((t_i64)table->elems_count);
}
