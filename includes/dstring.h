/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:47:39 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/08 15:54:09 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSTRING_H
# define DSTRING_H

# include "ft_mem.h"
# include "ft_string.h"
# include "stdlib.h"

# define DSTRING t_dyn_string
# define DSTR_BLK_SZ 64

# ifndef SIZE_T_MAX
#  define SIZE_T_MAX ((size_t)-1)
# endif

# ifndef SSIZE_T_MAX
#  define SSIZE_T_MAX ((ssize_t)0x0fffffffffffffff)
# endif

typedef struct	s_dyn_string
{
	char		*txt;
	ssize_t		strlen;
	ssize_t		bks;
}				t_dyn_string;

/*
** CREATES A NEW DSTRING FROM A SRC
**
** If src = 0, null dstring withouth malloc txt retutned
*/
DSTRING			*dstr_new(const char *src);

/*
** Deletes a DSTRING
*/
void			dstr_del(DSTRING **dst);

/*
** Inserts a src(ch/src) at the dst (changing the dst) before index ind;
** if ind=0, insert src before dst, if ind=strlen::dst inserts at the end;
*/
ssize_t			dstr_insert_str(DSTRING *dst, char *src, ssize_t ind);
ssize_t			dstr_insert_dstr(DSTRING *dst, DSTRING *src, ssize_t ind);
ssize_t			dstr_insert_ch(DSTRING *dst, char ch, ssize_t ind);

/*
** SPECIAL FOR PAVEL
** Insert making a new DSTRING from insertion and cuting-off a sdt by str
** f("abc", "d", 1) => "ad"
*/
DSTRING			*dstr_dstr_swpc(DSTRING *dst, DSTRING *ndst, ssize_t ind);
DSTRING			*dstr_str_swpc(DSTRING *dst, char *str, ssize_t ind);
DSTRING			*dstr_chr_swpc(DSTRING *dst, char ch, ssize_t ind);

/*
** Python slices at the C
** Returns a new string sliced from src.
** bi - begin index (if < 0, then index from the end)
** ei - end index, doesnt appear in new string. (<0 then f.t.e.)
*/
DSTRING			*dstr_slice(DSTRING *src, ssize_t bi, ssize_t ei);

/*
** Returns a new string CUTTED from src. (src is changing)
** bi - begin index (if < 0, then index from the end)
** ei - end index, doesnt appear in new string. (<0 then f.t.e.)
*/
DSTRING			*dstr_slice_cut(DSTRING **src, ssize_t bi, ssize_t ei);

/*
** Cutting a string from src. (src is changing)
** bi - begin index (if < 0, then index from the end)
** ei - end index, doesnt appear in new string. (<0 then f.t.e.)
** Returns -2 if allocation error or Returns -1 if input error
*/
int				dstr_slice_del(DSTRING **src, ssize_t bi, ssize_t ei);

/*
** Searches a ch/str/dstr in a (SRC);
** Returns an index of a ch (start index of a sub(str/dstr));
** If searching fails, returns SIZE_T_MAX ((size_t) -1)
*/
size_t			dstr_search_ch(const DSTRING *src, const char ch,\
size_t offset);
size_t			dstr_search_str(const DSTRING *src, const char *str,\
size_t offset);
size_t			dstr_search_dstr(const DSTRING *src, const DSTRING *dstr,\
size_t offset);

/*
** Deletes a string and give back a normal null-terminated string
*/
char			*dstr_flush(DSTRING **src);

/*
** Trimmes a DSTRING
** If use dstr_trim_this, it reallocates current DSTRING.
**		If allocation failes, its sets current DSTRING to a NULL.
** If use dstr_trim, it makes new trimmed DSTRING.
**		If allocation failes, its returns  NULL.
*/
DSTRING			*dstr_trim(DSTRING *dstr);
void			dstr_trim_this(DSTRING **dstr);

#endif
