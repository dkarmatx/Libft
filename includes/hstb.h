/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hstb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:59:45 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:12:17 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSTB_H
# define HSTB_H

# include "hashtable.h"

# define HS_MAGICWORD	0x00000000fee1600d

# define HT_OVER			-3
# define HT_LOCKED		-2
# define HT_EXISTS		-1

# ifndef NULL
#  define NULL (void *)0
# endif

typedef struct		s_key_value
{
	void			*val;
	char			*key;
}					t_kv;

typedef struct		s_hashtable_hidden
{
	t_u64			magic;
	t_kv			*heap;
	t_free_callbk	cleanf;
	t_hash_fn		hashf;
	size_t			elems_count;
	size_t			heap_size;
}					t_htb_hid;

/*
**	Returns a new index for element after double hashing.
**	If it already exists, returns -1, if this index is locked returns -2.
*/
t_i64				ht_b_getindex(t_htb_hid *tb, char const *str);
t_i64				ht_b_geths(t_htb_hid *tb, char const *str);

/*
**	Allocates a standart hashtable and it's heap by 1block size;
*/
t_htb_hid			*ht_b_alloca_std(size_t size);

/*
**	Resize and Rehash all elements in the hash table if space ended.
**	if allocation failed, returns -1, else 0.
*/
int					ht_b_heap_resize(t_htb_hid *tb);

/*
**	Check hash table id
**	returns NULL if bad id
**	returns pointer to ht else
*/
t_htb_hid			*ht_b_isid(t_ht_id id);

#endif
