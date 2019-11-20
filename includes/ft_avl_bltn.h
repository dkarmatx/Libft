/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_bltn.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 06:24:44 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:53:58 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_BLTN_H
# define FT_AVL_BLTN_H

# include "ft_avl_tree.h"
# include "ft_mem.h"
# include <stdlib.h>
# include "ft_string.h"

char			avlb_height(t_avln *node);

/*
** BUILTN FUNC
** Return balance factor of a AVL NODE
*/
char			avlb_bfactor(t_avln *node);

/*
** BUILTN FUNC
** fixing a height of a node
*/
void			avlb_fixh(t_avln *node);

/*
** BUILTN FUNC
** Small rotating to left
*/
t_avln			*avlb_rotate_sl(t_avln *node);

/*
** BUILTN FUNC
** Small rotating to right
*/
t_avln			*avlb_rotate_sr(t_avln *node);

/*
** BUILTN FUNC
** Balancing a sub-tree with root node
*/
t_avln			*avlb_balance(t_avln *node);

/*
** BUILTN FUNC
** {F} func taking a content address and deletes it
*/
void			avlb_rmnode(t_avln *node, void (*f)(void *));

/*
** BUILTN FUNC
** Change of old to a new node
*/
t_avln			*avlb_fake_node(t_avln *nd, t_avln *nw, void (*f)(void *));

/*
** BUILTN FUNC
** Return a root node at the end.
** Makes inserting operation to the tree and balance it after insert.
** IF NODE ALREADY EXISTS IT IS DELETE OLD EL AND CHANGE IT BY A NEW.
*/
t_avln			*avlb_insert(t_avln *node, t_avln *newn, void (*f)(void *));

/*
** BUILTN FUNC
** Cutting a succesor from the tree and saves it to {*min}
** Balance every node after it from down to up.
*/
t_avln			*avlb_sucut(t_avln *node, t_avln **min);

/*
** BUILTN FUNC
** Returning succesor of finded node and
** insert succesor in the cutted node place.
** Finded node's addres is saved in {*ct}.
*/
t_avln			*avlb_cutnd(t_avln *node, t_avln **ct);

/*
** BUILTN FUNC
** Returning a root tree at the and.
** Searching for a node to be cut and make balancing after all.
** The node will be saved at {*ct} if founded.
*/
t_avln			*avlb_cut(t_avln *node, const char *key, t_avln **ct);

/*
** BUILTN FUNC
** Returning a new node.
** Making it height is 1,
** and doesnt allocate, it just dereferencing the adresses of cnt key
*/
t_avln			*avlb_node_create(char *key, void *cnt, size_t sz);

/*
** BUILTN FUNC
** Recursive bypass of the tree and deleting it from down to up.
*/
int				avlb_stree_destroy(t_avln *node, void (*f)(void *));

/*
** BUILTN FUNC
** search for a node with key == {KEY}.
** Returns 0 if it is not exist.
*/
t_avln			*avlb_search(t_avln *node, const char *key);

/*
** BUILTN FUNC
** iterate every node of a tree and apply a function to each of them
** to get a words arrray.
*/
void			avlb_recur_trtowr(t_avln *nd, char **wr, int *k, \
DSTRING *(*f)(t_avln *));

#endif
