/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awl_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:55:51 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/08 06:20:45 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AWL_TREE_H
# define FT_AWL_TREE_H

# include <stdlib.h>

typedef struct			s_awl_node
{
	char				*key;
	struct s_awl_node	*left;
	struct s_awl_node	*right;
	void				*content;
	unsigned long		size;
	char				height;
}						t_awl_node;

int						ft_awl_set(t_awl_node **tree, const char *key,\
						void *content, size_t cont_size);
int						ft_awl_set_cc(t_awl_node **tree, const char *key,\
						void *content, size_t cont_size);
t_awl_node				*ft_awl_cut(t_awl_node **tree, const char *key);
int						ft_awl_del(t_awl_node **tree, const char *key, void (*f)(void *));
int						ft_awl_sizeof(t_awl_node *node);
int						ft_awl_tree_destroy(t_awl_node *node, void (*f)(void *));

#endif