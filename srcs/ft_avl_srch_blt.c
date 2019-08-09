/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_srch_blt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 07:04:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/09 07:09:40 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

t_avln			*avlb_search(t_avln *node, const char *key)
{
	int		cmp_res;

	if (!node)
		return (0);
	if (!(cmp_res = ft_strcmp(node->key, key)))
		return (node);
	return (cmp_res > 0 ? \
		avlb_search(node->left, key) : \
		avlb_search(node->right, key));
}
