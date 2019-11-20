/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_srch_blt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 07:04:07 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:24:10 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_bltn.h"
#include "dstring.h"

void		avlb_recur_trtowr(t_avln *nd, char **wr, int *k, \
DSTRING *(*f)(t_avln *))
{
	DSTRING		*result;

	if (nd == 0)
		return ;
	avlb_recur_trtowr(nd->left, wr, k, f);
	result = f(nd);
	wr[*k] = ft_strdup(result->txt);
	*k += 1;
	dstr_del(&result);
	avlb_recur_trtowr(nd->right, wr, k, f);
}

t_avln		*avlb_search(t_avln *node, const char *key)
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
