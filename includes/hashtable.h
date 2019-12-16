/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:46:00 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:12:33 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "hashfuncs.h"
# include <ctype.h>

# define HS_BLK_SZ		64
# define HT_ALREXIST	3
# define HT_BADACCESS	2
# define HT_ALLOCAFAIL	1
# define HT_OK			0

# define HT_SV_CONCURENT	0
# define HT_SV_SAFE		1

typedef void	*t_ht_id;
typedef void	(*t_free_callbk)(void *);
typedef t_u64	(*t_hash_fn)(char const *);

/*
**	Creates new hash table.
**	Allocates it and returns special id.
**	If allocation failed returns NULL.
**
**	@free_func -> pointer to a function wich frees content by its addr.
**		If content in hash table isnt freeable, send NULL here.
**
**	@hsfunc -> hash function. Send NULL if you are not intresed.
**		uint64 func(char const *)
**
**	@inisize -> size of new hashtable, if 0, it will be standart (HS_BLK_SZ)
*/
t_ht_id			ht_create(t_free_callbk free_func, t_hash_fn hsfunc, \
size_t ini_size);

/*
**	Deallocates hash table.
*/
void			ht_free(t_ht_id htid);

/*
**	Add a new element without duplicating it, only duplicates key value.
**	If sv == HT_SV_CONCURENT then set new value for key,
**	if HT_SV_SAFE then returns HT_EXIST
**	Returns:
**		0 if OK
**		1 if Allocation failed HT_ALLOCA
**		2 input error HT_BADACCESS
**		3 if safe and exists HT_EXISTS
*/
int				ht_addptr(t_ht_id htid, char *const key, void *ptr, int sv);

/*
**	Add a new element and duplicates it.
**	New element will be allocated by @size.
**	If its ptr==NULL, doesnt allocates ptr.
**	set new value for key always
**	Returns:
**		0 if OK
**		1 if Allocation failed
**		2 input error (key is null or size is null)
*/
int				ht_add(t_ht_id htid, char *const key, void *ptr, \
size_t size);

/*
**	Add a new element and duplicates it.
**	New element will be allocated by @size.
**	If its ptr==NULL, doesnt allocates ptr.
**	if element exists then returns HT_EXIST
**	Returns:
**		0 if OK
**		1 if Allocation failed HT_ALLOCA
**		2 input error HT_BADACCESS
**		3 if exists HT_EXISTS
*/
int				ht_addsafe(t_ht_id htid, char *const key, void *ptr, \
size_t size);

/*
**	Returns an pointer to an element.
**	If element is not occured, returns NULL.
*/
void			*ht_get(t_ht_id htid, char *const key);

/*
**	Deletes element from table and frees it with callback
*/
void			ht_rm(t_ht_id htid, char *const key);

/*
**	Deletes element from table and returns pointer on it
**	Returns NULL if element isn't occured in the table
*/
void			*ht_cut(t_ht_id htid, char *const key);

/*
**	Returns size of a table, if table id is bad, then returns -1
*/
t_i64			ht_count(t_ht_id id);

#endif
