/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awl_bltn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:30:37 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/06 18:23:05 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awl_tree.h"
#include "ft_mem.h"
#include <stdlib.h>
#include "ft_string.h"

char			ft_awl_height(t_awl_node *node)
{
	return (node ? node->height : 0);
}

char			ft_awl_bfactor(t_awl_node *node)
{
	return (ft_awl_height(node->right) - ft_awl_height(node->left));
}

void			ft_awl_fixh(t_awl_node *node)
{
	const char	hl = ft_awl_height(node->left);
	const char	hr = ft_awl_height(node->right);
	// DORABOTKA!!!!
	node->height = (hl > hr ? hl : hr) + 1;
}

t_awl_node		*ft_awl_rotate_sl(t_awl_node *node)
{
	t_awl_node		*rnode;

	rnode = node->right;
	node->right = rnode->left;
	rnode->left = node;
	ft_awl_fixh(node);
	ft_awl_fixh(rnode);
	return (rnode);
}

t_awl_node		*ft_awl_rotate_sr(t_awl_node *node)
{
	t_awl_node		*lnode;

	lnode = node->left;
	node->left = lnode->right;
	lnode->right = node;
	ft_awl_fixh(node);
	ft_awl_fixh(lnode);
	return (lnode);
}

t_awl_node		*ft_awl_balance(t_awl_node *node)
{
	char		bfac;

	if (!node)
		return (0);
	ft_awl_fixh(node);
	bfac = ft_awl_bfactor(node);
	if (bfac == 2)
	{
		if ((bfac = ft_awl_bfactor(node->right)) < 0)
			node->right = ft_awl_rotate_sr(node->right);
		return (ft_awl_rotate_sl(node));
	}
	if (bfac == -2)
	{
		if ((bfac = ft_awl_bfactor(node->left)) > 0)
			node->left = ft_awl_rotate_sl(node->left);
		return (ft_awl_rotate_sr(node));
	}
	return (node);
}

t_awl_node		*ft_awl_node_create(char *key, void *cnt, size_t sz)
{
	t_awl_node	*node;

	if (!(node = ft_memalloc(sizeof(t_awl_node))))
		return (0);
	node->key = key;
	node->size = sz;
	node->content = cnt;
	node->height = 1;
	return (node);
}

t_awl_node		*ft_awl_edit_node(t_awl_node *nd, void *cont, size_t sz)
{
	nd->size = sz;
	if (nd->content)
		free(nd->content);
	nd->content = cont;
	return (nd);
}

t_awl_node		*ft_awl_insert_bltn(t_awl_node *node, char *key,\
				 void *cnt, size_t sz)
{
	if (node == 0)
		return (ft_awl_node_create(key, cnt, sz));
	if (ft_strcmp(node->key, key) > 0)
		node->left = ft_awl_insert_bltn(node->left, key, cnt, sz);
	else if (ft_strcmp(node->key, key) < 0)
		node->right = ft_awl_insert_bltn(node->right, key, cnt, sz);
	else
		return (ft_awl_edit_node(node, cnt, sz));
	return (ft_awl_balance(node));
}

int				ft_awl_set_cc(t_awl_node **tree, const char *key,\
				void *content, size_t cont_size)
{
	if (tree == 0)
		return (-1);
	*tree = ft_awl_insert_bltn(*tree, (char *)key, content, cont_size);
	return (0);
}

int				ft_awl_set(t_awl_node **tree, const char *key,\
				void *content, size_t cont_size)
{
	char	*keyd;
	void	*contd;

	if (tree == 0)
		return (-1);
	if (!(contd = ft_memdup(content, cont_size)))
		return (-2);
	if (!(keyd = ft_strdup(key)))
	{
		free(contd);
		return (-2);
	}
	*tree = ft_awl_insert_bltn(*tree, keyd, contd, cont_size);
	return (0);
}
