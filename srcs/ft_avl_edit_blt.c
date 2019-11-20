/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_edit_blt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 06:55:13 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:20:06 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

t_avln		*avlb_insert(t_avln *node, t_avln *newn, void (*f)(void *))
{
	if (node == 0)
		return (newn);
	if (ft_strcmp(node->key, newn->key) > 0)
		node->left = avlb_insert(node->left, newn, f);
	else if (ft_strcmp(node->key, newn->key) < 0)
		node->right = avlb_insert(node->right, newn, f);
	else
		return (avlb_fake_node(node, newn, f));
	return (avlb_balance(node));
}

t_avln		*avlb_sucut(t_avln *node, t_avln **min)
{
	if (node->left == 0 && (*min = node))
		return (0);
	if (avlb_sucut(node->left, min) == 0)
		node->left = node->left->right;
	return (avlb_balance(node));
}

t_avln		*avlb_cutnd(t_avln *node, t_avln **ct)
{
	*ct = node;
	if (node->left == 0 && node->right == 0)
		return (0);
	if (node->left == 0)
		return (node->right);
	if (node->right == 0)
		return (node->left);
	if (avlb_sucut(node->right, &node) != 0)
		node->right = (*ct)->right;
	node->left = (*ct)->left;
	return (node);
}

t_avln		*avlb_cut(t_avln *node, const char *key, t_avln **ct)
{
	const int		cmp_res = ft_strcmp(key, node->key);

	if (!node)
		return (0);
	if (cmp_res > 0)
		node->right = avlb_cut(node->right, key, ct);
	else if (cmp_res < 0)
		node->left = avlb_cut(node->left, key, ct);
	else
		node = avlb_cutnd(node, ct);
	return (avlb_balance(node));
}
