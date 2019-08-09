/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_api_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 07:00:30 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/09 07:14:37 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

int				ft_avl_sizeof(t_avln *node)
{
	return (node ? \
	(1 + ft_avl_sizeof(node->left) + ft_avl_sizeof(node->right)) \
	: 0);
}

t_avln			*ft_avl_search(t_avl_tree *tree, const char *key)
{
	if (tree == 0)
		return (0);
	return (avlb_search(tree->root, key));
}
