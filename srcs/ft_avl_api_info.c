/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_api_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 07:00:30 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/17 20:04:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"
#include "dstring.h"

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

DSTRING			*avln_todstring_key_val(t_avln *node)
{
	DSTRING		*res;

	res = dstr_new(node->key);
	dstr_insert_str(res, "=", res->strlen);
	dstr_insert_str(res, (char *)node->content, res->strlen);
	return (res);
}

char			**ft_avl_tree_to_warr(t_avl_tree *tree, \
DSTRING *(*ds)(t_avln *))
{
	int			amount;
	char		**warr;
	int			k;

	k = 0;
	if (!tree->root)
		return (0);
	amount = ft_avl_sizeof(tree->root);
	if (!(warr = ft_memalloc(sizeof(char *) * (amount + 1))))
		return (0);
	avlb_recur_trtowr(tree->root, warr, &k, ds);
	return (warr);
}
