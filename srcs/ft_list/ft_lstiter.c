/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 06:56:55 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:16:57 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*next_lst;

	if (lst && f)
	{
		next_lst = lst;
		while (next_lst)
		{
			(*f)(next_lst);
			next_lst = next_lst->next;
		}
	}
}
