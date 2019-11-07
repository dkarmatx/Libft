/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:28:29 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/07 09:12:31 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "dstring.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void		b_ind_gnl(DSTRING *src, ssize_t bi, ssize_t ei, ssize_t *ri)
{
	ri[0] = (bi < 0) ? (src->strlen) + bi : bi;
	ri[1] = (ei < 0) ? (src->strlen) + ei : ei;
	ri[0] = (ri[0] < 0) ? 0 : ri[0];
	ri[1] = (ri[1] < 0) ? 0 : ri[1];
	ri[0] = (ri[0] > src->strlen) ? src->strlen : ri[0];
	ri[1] = (ri[1] > src->strlen) ? src->strlen : ri[1];
}

static DSTRING	*dstr_slice_cut_gnl(DSTRING **src, ssize_t bi, ssize_t ei)
{
	DSTRING		*dstr_sl;
	DSTRING		*dstr_deld;
	DSTRING		*dstr_ol[2];
	ssize_t		ri[4];

	b_ind_gnl(*src, bi, ei, ri);
	if (ri[0] >= ri[1])
		return (dstr_new(""));
	ri[2] = 0;
	ri[3] = (*src)->strlen;
	dstr_ol[0] = dstr_slice(*src, ri[2], ri[0]);
	dstr_ol[1] = dstr_slice(*src, ri[1], ri[3]);
	dstr_sl = dstr_slice(*src, ri[0], ri[1] - 1 > 0 ? ri[1] - 1 : 0);
	if (!dstr_ol[0] || !dstr_sl || !dstr_ol[1])
		return (0);
	dstr_del(src);
	*src = dstr_ol[0];
	dstr_deld = dstr_ol[1];
	if ((dstr_insert_dstr(*src, dstr_ol[1], SSIZE_T_MAX)) < 0)
		return (0);
	dstr_del(&dstr_deld);
	return (dstr_sl);
}

int				get_next_line(const int fd, DSTRING **line)
{
	static DSTRING	*buf_fd[FDS_MAX_LIMIT];
	char			buf_rd[BUFF_SIZE + 1];
	ssize_t			rd;
	size_t			ind;

	if (fd < 0 || (!line && (ind = 0) == 0))
		return (-1);
	if ((rd = 1) && !buf_fd[fd])
		buf_fd[fd] = dstr_new("");
	ind = dstr_search_ch(buf_fd[fd], '\n', 0);
	while (ind == (size_t)-1 && (rd = read(fd, buf_rd, BUFF_SIZE)) > 0)
	{
		buf_rd[rd] = '\0';
		dstr_insert_str(buf_fd[fd], buf_rd, buf_fd[fd]->strlen);
		if ((ind = dstr_search_ch(buf_fd[fd], '\n', 0)) != (size_t)-1)
			break ;
	}
	if (ind != (size_t)-1)
		*line = dstr_slice_cut_gnl(&buf_fd[fd], 0, ind + 1);
	else
		*line = dstr_slice_cut(&buf_fd[fd], 0, buf_fd[fd]->strlen);
	if (rd <= 0 && !(*line)->strlen && ind == (size_t)-1 && !buf_fd[fd]->strlen)
		return ((int)rd);
	return (1);
}
