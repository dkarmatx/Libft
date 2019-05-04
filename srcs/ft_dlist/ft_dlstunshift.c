/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstunshift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:13:29 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/05 00:50:42 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstunshift(t_dlist **dlst, t_dlist *nlst)
{
	if (!nlst || !dlst)
		return ;
	nlst->next = *dlst;
	if (*dlst)
		(*dlst)->prev = nlst;
	*dlst = nlst;
}
