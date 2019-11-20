/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbuffer_io.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:10:35 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:19:00 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lbuffer.h"
#include <unistd.h>
#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"

t_lbuf			*ft_lb_readbytes(int fd, ssize_t *summ_rmem)
{
	ssize_t		rmem;
	ssize_t		frmem;
	char		buff[LB_STR_SZ];
	t_lbuf		*buffer[2];

	if (!(buffer[0] = ft_memalloc(sizeof(t_lbuf))))
		return (0);
	frmem = 0;
	buffer[1] = buffer[0];
	while ((rmem = read(fd, buff, LB_STR_SZ)) > 0 && rmem)
	{
		if (rmem == LB_STR_SZ && !(buffer[1]->next = \
		ft_memalloc(sizeof(t_lbuf))))
		{
			frmem = -1;
			break ;
		}
		ft_memcpy(buffer[1]->str, buff, rmem);
		buffer[1] = buffer[1]->next;
		frmem += rmem;
		if (rmem < LB_STR_SZ)
			break ;
	}
	summ_rmem ? *summ_rmem = frmem : 0;
	return (buffer[0]);
}

size_t			ft_lb_strlen(t_lbuf *buff)
{
	t_lbuf		*buff_it;
	size_t		len;

	len = 0;
	if (!(buff_it = buff))
		return (0);
	len = 0;
	while ((buff_it->next) && (buff_it = buff_it->next))
		len += LB_STR_SZ;
	len += ft_strlen(buff_it->str);
	return (len);
}

char			*ft_lb_flush(t_lbuf *buff)
{
	ssize_t		len;
	char		*str;
	char		*stri;
	t_lbuf		*buff_it;
	t_lbuf		*buff_d;

	if (!(buff_it = buff))
		return (0);
	len = (ssize_t)ft_lb_strlen(buff);
	if (!(str = ft_strnew(len)))
		return (0);
	stri = str;
	while (buff_it)
	{
		stri = ft_strcate(stri, buff_it->str);
		buff_d = buff_it;
		buff_it = buff_it->next;
		free(buff_d);
	}
	return (str);
}

char			*ft_lb_getstr(t_lbuf *buff)
{
	ssize_t		len;
	char		*str;
	char		*stri;
	t_lbuf		*buff_it;

	if (!(buff_it = buff))
		return (0);
	len = (ssize_t)ft_lb_strlen(buff);
	if (!(str = ft_strnew(len)))
		return (0);
	stri = str;
	while (buff_it)
	{
		stri = ft_strcate(stri, buff_it->str);
		buff_it = buff_it->next;
	}
	return (str);
}
