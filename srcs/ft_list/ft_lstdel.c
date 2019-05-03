/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:38:34 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:16:04 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*del_goal;
	t_list		*iter;

	if (alst && *alst && del)
	{
		iter = *alst;
		while (iter)
		{
			del_goal = iter;
			iter = iter->next;
			ft_lstdelone(&del_goal, del);
		}
		*alst = 0;
	}
}
