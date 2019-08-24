/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:36:12 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/24 07:35:39 by hgranule         ###   ########.fr       */
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

/*
** Create a new element of double-list, and duplicate
** content from adress {CONTENT} of size {SIZE} in it.
*/
t_dlist				*ft_dlstnew(void *content, size_t size);

/*
** Create a new element of double-list, and copy address
** of content {CONTENT} and size of content {SIZE} to element.
*/
t_dlist				*ft_dlstnew_cc(void *content, size_t size);

/*
** Pushes new element {NLST} to the end of the list {DLST}.
*/
void				ft_dlstpush(t_dlist **dlst, t_dlist *nlst);

/*
** Pushes new element {NLST} to the beging of the list {DLST}.
*/
void				ft_dlstunshift(t_dlist **dlst, t_dlist *nlst);

/*
** Returns a adress of {IND}s element of list {CDLST} from the begin
*/
t_dlist				*ft_dlstget(t_dlist *cdlst, size_t ind);

/*
** Returns a adress of {IND}s element of list {CDLST} from the end
*/
t_dlist				*ft_dlstrget(t_dlist *cdlst, size_t ind);

/*
** Inserts a element {INSRT} after {PRV} and before {NXT}
*/
void				ft_dlstinsert(t_dlist *insrt, t_dlist *prv, t_dlist *nxt);

/*
** Cuts the element, applies RMFUNC to the content and then frees element.
*/
void				ft_dlst_delcut(t_dlist **deldlst, \
void (*rmfunc)(void *, size_t));

/*
** Cuts the list {*CUTDLST} and returning it.
*/
t_dlist				*ft_dlstcut(t_dlist **cutdlst);

/*
** Deletes the {N} elemnets from the begin of the list {DLS} with func RMF()
** if {N} == 0, then removes the hole list.
*/
void				ft_dlst_delf(t_dlist **dls, size_t n, \
void (*rmf)(void *, size_t));

/*
** Cuting the first element from begin of the {LIST} and returns it
*/
t_dlist				*ft_dlstshift(t_dlist **list);

/*
** Swap to elemnt of any list
*/
void				ft_dlstswap(t_dlist *a, t_dlist *b);

/*
** Sorting list {DL}.
** {CMP} - compare function which takes content of elements and compare it
*/
void				ft_dlst_gnsort(t_dlist **dl, int (*cmp)(void *, void *));
void				ft_dlst_rgnsort(t_dlist **dl, int (*cmp)(void *, void *));

/*
** Counts amount of elements which was applied by
** a func {F} and returned non zero
*/
size_t				ft_dlst_count(t_dlist *start, int (*f)(void *));

/*
** Makes a snap of elements's content to null-terminated array.
** If f => content => non-zero, it will be in a snapshot.
*/
void				**ft_dlst_snaparr(t_dlist *start, int (*f)(void *));

/*
** ============ OLD FUNCS =====================================================
*/

/*
** DOENST SUPPORTS ANYMORE (use ft_dlst_delf)
*/
void				ft_dlstdel(t_dlist **dlst, size_t n);
/*
** DOESNT SUPPORTS ANYMORE (use ft_dlst_delcut())
*/
void				ft_dlstrmelem(t_dlist **deldlst);

#endif
