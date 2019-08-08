/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awl_bltn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:30:37 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/08 06:21:41 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awl_tree.h"
#include "ft_mem.h"
#include <stdlib.h>
#include "ft_string.h"

char			awlb_height(t_awl_node *node)
{
	return (node ? node->height : 0);
}

char			awlb_bfactor(t_awl_node *node)
{
	return (awlb_height(node->right) - awlb_height(node->left));
}

void			awlb_fixh(t_awl_node *node)
{
	const char	hl = awlb_height(node->left);
	const char	hr = awlb_height(node->right);
	// DORABOTKA!!!!
	node->height = (hl > hr ? hl : hr) + 1;
}

t_awl_node		*awlb_rotate_sl(t_awl_node *node)
{
	t_awl_node		*rnode;

	rnode = node->right;
	node->right = rnode->left;
	rnode->left = node;
	awlb_fixh(node);
	awlb_fixh(rnode);
	return (rnode);
}

t_awl_node		*awlb_rotate_sr(t_awl_node *node)
{
	t_awl_node		*lnode;

	lnode = node->left;
	node->left = lnode->right;
	lnode->right = node;
	awlb_fixh(node);
	awlb_fixh(lnode);
	return (lnode);
}

t_awl_node		*awlb_balance(t_awl_node *node)
{
	char		bfac;

	if (!node)
		return (0);
	awlb_fixh(node);
	bfac = awlb_bfactor(node);
	if (bfac == 2)
	{
		if ((bfac = awlb_bfactor(node->right)) < 0)
			node->right = awlb_rotate_sr(node->right);
		return (awlb_rotate_sl(node));
	}
	if (bfac == -2)
	{
		if ((bfac = awlb_bfactor(node->left)) > 0)
			node->left = awlb_rotate_sl(node->left);
		return (awlb_rotate_sr(node));
	}
	return (node);
}

t_awl_node		*awlb_node_create(char *key, void *cnt, size_t sz)
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

t_awl_node		*awlb_edit_node(t_awl_node *nd, void *cont, size_t sz)
{
	nd->size = sz;
	if (nd->content)
		free(nd->content);
	nd->content = cont;
	return (nd);
}

t_awl_node		*awlb_insert(t_awl_node *node, char *key,\
				 void *cnt, size_t sz)
{
	if (node == 0)
		return (awlb_node_create(key, cnt, sz));
	if (ft_strcmp(node->key, key) > 0)
		node->left = awlb_insert(node->left, key, cnt, sz);
	else if (ft_strcmp(node->key, key) < 0)
		node->right = awlb_insert(node->right, key, cnt, sz);
	else
		return (awlb_edit_node(node, cnt, sz));
	return (awlb_balance(node));
}

// изначально принимает начало правого дерева
//
// устанавливает в min минимальный элемент, и вырезает его из дерева
t_awl_node		*awlb_sucut(t_awl_node *node, t_awl_node **min)
{
	if (node->left == 0 && (*min = node))
		return (0);
	if (awlb_sucut(node->left, min) == 0)
		node->left = node->left->right;
	return (awlb_balance(node));
}

// возвращает новый текущий узел
t_awl_node		*awlb_cutnd(t_awl_node *node, t_awl_node **ct)
{
	*ct = node;
	if (node->left == 0 && node->right == 0)
		return (0);
	if (node->left == 0)
		return (node->right);
	if (node->right == 0)
		return (node->left);
	if (awlb_sucut(node->right, &node) != 0)
		node->right = (*ct)->right;
	node->left = (*ct)->left;
	return (node);
}

// возвращает текущий узел
t_awl_node		*awlb_cut(t_awl_node *node, const char *key, t_awl_node **ct)
{
	const int		cmp_res = ft_strcmp(key, node->key);

	if (!node)
		return (0);
	if (cmp_res > 0)
		node->right = awlb_cut(node->right, key, ct);
	else if (cmp_res < 0)
		node->left = awlb_cut(node->left, key, ct);
	else
		node = awlb_cutnd(node, ct);
	return (awlb_balance(node));
}

void			awlb_rmnode(t_awl_node *node, void (*f)(void *))
{
	if (!node)
		return ;
	if (node->content && node->size && f)
		f(node->content);
	free(node->key);
	free(node);
}

t_awl_node		*ft_awl_cut(t_awl_node **tree, const char *key)
{
	t_awl_node		*cutten;

	if (tree == 0)
		return (0);
	*tree = awlb_cut(*tree, key, &cutten);
	return (cutten);
}

int				ft_awl_del(t_awl_node **tree, const char *key, void (*f)(void *))
{
	t_awl_node		*cutten;

	if (tree == 0)
		return (-1);
	*tree = awlb_cut(*tree, key, &cutten);
	awlb_rmnode(cutten, f);
	return (0);
}

int				ft_awl_sizeof(t_awl_node *node)
{
	return (node ? \
	(1 + ft_awl_sizeof(node->left) + ft_awl_sizeof(node->right)) \
	: 0);
}

int				ft_awl_tree_destroy(t_awl_node *node, void (*f)(void *))
{
	if (node == 0)
		return (0);
	ft_awl_tree_destroy(node->left, f);
	ft_awl_tree_destroy(node->right, f);
	awlb_rmnode(node, f);
	return (0);
}

int				ft_awl_set_cc(t_awl_node **tree, const char *key,\
				void *content, size_t cont_size)
{
	char	*keyd;

	if (tree == 0)
		return (-1);
	if (!(keyd = ft_strdup(key)))
		return (-2);
	*tree = awlb_insert(*tree, keyd, content, cont_size);
	return (0);
}

int				ft_awl_set(t_awl_node **tree, const char *key,\
				void *content, size_t cont_size)
{
	char	*keyd;
	void	*contd;

	contd = 0;
	if (tree == 0)
		return (-1);
	if (content && cont_size)
		if (!(contd = ft_memdup(content, cont_size)))
			return (-2);
	if (!(keyd = ft_strdup(key)))
	{
		if (contd)
			free(contd);
		return (-2);
	}
	*tree = awlb_insert(*tree, keyd, contd, cont_size);
	return (0);
}
