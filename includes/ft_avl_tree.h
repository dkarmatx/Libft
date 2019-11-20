/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:55:51 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:53:09 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_TREE_H
# define FT_AVL_TREE_H

# include <stdlib.h>
# include "dstring.h"

typedef struct			s_avl_node
{
	char				*key;
	struct s_avl_node	*left;
	struct s_avl_node	*right;
	void				*content;
	unsigned long		size;
	char				height;
}						t_avln;

typedef struct			s_avl_tree
{
	struct s_avl_node	*root;
	void				(*rm_func)(void *cont);
}						t_avl_tree;

/*
** API FUNC
** Creating a new tree struct
** {rm_func()} - fucntion wich deletes content of a nodes
*/
t_avl_tree				*ft_avl_tree_create(void (*rm_f));

/*
** API FUNC
** Inserts newn node at the tree, if node with this key already exits,
** removes it and swapping it with newn.
** IT IS USING A RM_FUNC FROM {TREE} FOR DELETING NODE->CONTENT.
*/
int						ft_avl_set(t_avl_tree *tree, t_avln *newn);

/*
** API FUNC
** Creates new node with redereferencing cont to node->content.
** RETURN 0 IF FAILS.
*/
t_avln					*ft_avl_node_cc(char *key, void *cont, size_t sz);

/*
** API FUNC
** Creates new node with duplicating a CONTENT of size SZ.
** RETURN 0 IF FAILS
*/
t_avln					*ft_avl_node(char *key, void *cont, size_t sz);

/*
** API FUNC
** Returns amount of nodes in sub-tree with root node {NODE}
*/
int						ft_avl_sizeof(t_avln *node);

/*
** API FUNC
** Deletes a node with key {KEY} from a tree {TREE}
** IT IS USING A RM_FUNC
*/
int						ft_avl_del(t_avl_tree *tree, const char *key);

/*
** API FUNC
** Cuts a node with key {KEY} from a tree {TREE}
** Returns a cutted node.
*/
t_avln					*ft_avl_cut(t_avl_tree *tree, const char *key);

/*
** API FUNC
** FREES A TREE
** IT IS USING RM_FUNC FOR A CONTENT
*/
int						ft_avl_tree_free(t_avl_tree *tree);

/*
** API FUNC
** SEARCHING for an element and returns a goal node.
** Returns 0 if searching fails
*/
t_avln					*ft_avl_search(t_avl_tree *tree, const char *key);

/*
** FUNCTION TAKES A CONTENT OF A TREE AND RETURN DSTRING
**
** STANDART OF TO DSTRING FUNCTION OF AVL_TREE
*/
DSTRING					*avln_todstring_key_val(t_avln *node);

/*
** Function for creating a array of words from nodes.
**
** Callback function f creates a DSTING-words from nodes.
*/
char					**ft_avl_tree_to_warr(t_avl_tree *tree, \
DSTRING *(*to_dsting_f)(t_avln *));

#endif
