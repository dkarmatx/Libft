/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_maparr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:53:02 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/06 07:29:06 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_mem.h"
#include <stdlib.h>

void		**ft_dlst_snaparr(t_dlist *start, int (*f)(void *))
{
	const size_t	len = ft_dlst_count(start, f);
	const void		**cont_arr = ft_memalloc(sizeof(void *) * (len + 1));
	size_t			i;

	i = -1;
	if (cont_arr == 0)
		return (0);
	while (start && (i + 1) < len)
	{
		if ((*f)(start->content))
			cont_arr[++i] = start->content;
		start = start->content;
	}
	return ((void **)cont_arr);
}
