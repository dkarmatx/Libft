/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:47:39 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/17 17:39:37 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSTRING_H
# define DSTRING_H

# include "ft_mem.h"
# include "ft_string.h"
# include "stdlib.h"

# define DSTRING t_dyn_string

# define DSTR_BLK_SZ 512

typedef struct		s_dyn_string
{
	char			*txt;
	ssize_t			strlen;
	ssize_t			bks;
}					t_dyn_string;

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

#endif
