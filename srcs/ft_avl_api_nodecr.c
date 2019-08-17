/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_api_nodecr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 06:57:05 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/17 20:02:51 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"

t_avln			*ft_avl_node(char *key, void *cont, size_t sz)
{
	t_avln		*new_node;
	char		*keyd;
	void		*contd;

	if (!sz || !cont)
		contd = 0;
	else if (!(contd = ft_memdup(cont, sz)))
		return (0);
	if (!(keyd = ft_strdup(key)))
	{
		contd ? free(contd) : 0;
		return (0);
	}
	if (!(new_node = avlb_node_create(keyd, contd, sz)))
	{
		contd ? free(contd) : 0;
		free(keyd);
		return (0);
	}
	return (new_node);
}

t_avln			*ft_avl_node_cc(char *key, void *cont, size_t sz)
{
	t_avln		*new_node;
	char		*keyd;

	if (!(keyd = ft_strdup(key)))
		return (0);
	if (!(new_node = avlb_node_create(keyd, cont, sz)))
	{
		free(keyd);
		return (0);
	}
	return (new_node);
}

int				ft_avl_set(t_avl_tree *tree, t_avln *newn)
{
	if (tree == 0 || newn == 0)
		return (-1);
	tree->root = avlb_insert(tree->root, newn, tree->rm_func);
	return (0);
}

t_avl_tree		*ft_avl_tree_create(void (*rm_f))
{
	t_avl_tree		*tree;

	if (!(tree = ft_memalloc(sizeof(t_avl_tree))))
		return (0);
	tree->rm_func = rm_f;
	return (tree);
}
