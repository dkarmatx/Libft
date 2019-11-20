/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_utils_blt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 06:52:16 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:20:23 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

char		avlb_height(t_avln *node)
{
	return (node ? node->height : 0);
}

void		avlb_rmnode(t_avln *node, void (*f)(void *))
{
	if (!node)
		return ;
	if (node->content && f)
		f(node->content);
	free(node->key);
	free(node);
}

t_avln		*avlb_fake_node(t_avln *nd, t_avln *nw, void (*f)(void *))
{
	nw->left = nd->left;
	nw->right = nd->right;
	nw->height = nd->height;
	avlb_rmnode(nd, f);
	return (nw);
}

t_avln		*avlb_node_create(char *key, void *cnt, size_t sz)
{
	t_avln	*node;

	if (!(node = ft_memalloc(sizeof(t_avln))))
		return (0);
	node->key = key;
	node->size = sz;
	node->content = cnt;
	node->height = 1;
	return (node);
}

int			avlb_stree_destroy(t_avln *node, void (*f)(void *))
{
	if (node == 0)
		return (0);
	avlb_stree_destroy(node->left, f);
	avlb_stree_destroy(node->right, f);
	avlb_rmnode(node, f);
	return (0);
}
