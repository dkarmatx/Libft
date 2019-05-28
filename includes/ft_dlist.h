/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:36:12 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/28 14:04:00 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <string.h>

typedef struct		s_dlist
{
	void			*content;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlstnew(void *content, size_t size);
void				ft_dlstpush(t_dlist **dlst, t_dlist *nlst);
void				ft_dlstunshift(t_dlist **dlst, t_dlist *nlst);
t_dlist				*ft_dlstget(t_dlist *cdlst, size_t ind);
t_dlist				*ft_dlstrget(t_dlist *cdlst, size_t ind);
void				ft_dlstinsert(t_dlist *insrt, t_dlist *prv, t_dlist *nxt);
void				ft_dlstrmelem(t_dlist **deldlst);
t_dlist				*ft_dlstcut(t_dlist **cutdlst);
void				ft_dlstdel(t_dlist **dlst, size_t n);
t_dlist				*ft_dlstshift(t_dlist **list);
void				ft_dlstswap(t_dlist *a, t_dlist *b);
void				ft_dlst_gnsort(t_dlist **, int (*cmp)(void *, void *));
void				ft_dlst_rgnsort(t_dlist **, int (*cmp)(void *, void *));

#endif
