/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:57:42 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/03 07:04:04 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

size_t		ft_dlst_count(t_dlist *start, int (*f)(void *))
{
	size_t		len;

	len = 0;
	while (start)
	{
		if ((*f)(start->content))
			++len;
		start->next;
	}
	return (len);
}
