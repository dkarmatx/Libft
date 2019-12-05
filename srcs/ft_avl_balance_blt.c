/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_balance_blt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:30:37 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/05 19:57:24 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

char		avlb_bfactor(t_avln *node)
{
	return (avlb_height(node->right) - avlb_height(node->left));
}

void		avlb_fixh(t_avln *node)
{
	const char	hl = avlb_height(node->left);
	const char	hr = avlb_height(node->right);

	node->height = (hl > hr ? hl : hr) + 1;
}

t_avln		*avlb_rotate_sl(t_avln *node)
{
	t_avln		*rnode;

	rnode = node->right;
	node->right = rnode->left;
	rnode->left = node;
	avlb_fixh(node);
	avlb_fixh(rnode);
	return (rnode);
}

t_avln		*avlb_rotate_sr(t_avln *node)
{
	t_avln		*lnode;

	lnode = node->left;
	node->left = lnode->right;
	lnode->right = node;
	avlb_fixh(node);
	avlb_fixh(lnode);
	return (lnode);
}

t_avln		*avlb_balance(t_avln *node)
{
	char		bfac;

	if (!node)
		return (0);
	avlb_fixh(node);
	bfac = avlb_bfactor(node);
	if (bfac == 2)
	{
		if ((bfac = avlb_bfactor(node->right)) < 0)
			node->right = avlb_rotate_sr(node->right);
		node = avlb_rotate_sl(node);
	}
	if (bfac == -2)
	{
		if ((bfac = avlb_bfactor(node->left)) > 0)
			node->left = avlb_rotate_sl(node->left);
		node = avlb_rotate_sr(node);
	}
	return (node);
}
