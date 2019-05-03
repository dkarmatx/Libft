/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 07:02:05 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:17:18 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

inline static void	delete_an_conte(void *cont, size_t size)
{
	if (size)
		free(cont);
}

inline static void	map_maker(t_list **map, t_list **map_n,
t_list **map_b, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;

	if (!(tmp = (*f)((*map_n))))
		ft_lstdelone(map_n, &delete_an_conte);
	else
	{
		if (tmp != (*map_n))
		{
			ft_lstdelone(map_n, &delete_an_conte);
			(*map_n) = tmp;
		}
		if ((*map))
			(*map)->next = (*map_n);
		(*map) = (*map_n);
		if (!(*map_b))
			(*map_b) = (*map);
	}
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*next_lst;
	t_list		*map;
	t_list		*map_n;
	t_list		*map_b;

	map_b = 0;
	map = 0;
	if (lst && f)
	{
		next_lst = lst;
		while (next_lst)
		{
			if (!(map_n = ft_lstnew(next_lst->content, next_lst->content_size)))
			{
				ft_lstdel(&map_b, &delete_an_conte);
				return (0);
			}
			map_maker(&map, &map_n, &map_b, f);
			next_lst = next_lst->next;
		}
	}
	return (map_b);
}
