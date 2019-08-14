/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:47:39 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/14 19:42:00 by hgranule         ###   ########.fr       */
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

DSTRING			*dstr_new(const char *src);
ssize_t			dstr_insert_str(DSTRING *dst, DSTRING *src, ssize_t ind);
DSTRING			*dstr_slice(DSTRING *src, ssize_t bi, ssize_t ei);

#endif
