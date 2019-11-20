/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 09:46:47 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:25:27 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_tools.h"

static t_tspec		g_timer;

int					dbg_timer_init(t_tspec *spec)
{
	extern t_tspec	g_timer;

	if (spec == 0)
		return (clock_gettime(CLOCK_REALTIME, &g_timer));
	g_timer.tv_nsec = spec->tv_nsec;
	g_timer.tv_sec = spec->tv_sec;
	return (0);
}

int					dbg_timer_sub(t_tspec *dst, t_tspec *src)
{
	t_tspec			res;

	res.tv_nsec = 0;
	res.tv_sec = 0;
	res.tv_sec = dst->tv_sec - src->tv_sec;
	if (dst->tv_nsec >= src->tv_nsec)
		res.tv_nsec = dst->tv_nsec - src->tv_nsec;
	else
	{
		--(res.tv_sec);
		res.tv_nsec = (dst->tv_nsec + 1000000000) - src->tv_nsec;
	}
	if (res.tv_sec > dst->tv_sec)
	{
		dst->tv_sec = 0;
		dst->tv_nsec = 0;
		return (-2);
	}
	dst->tv_nsec = res.tv_nsec;
	dst->tv_sec = res.tv_sec;
	return (0);
}

int					dbg_timer_checkp(t_tspec *ctimer)
{
	extern t_tspec	g_timer;

	if (clock_gettime(CLOCK_REALTIME, ctimer) < 0)
		return (-1);
	if (dbg_timer_sub(ctimer, &g_timer) < 0)
		return (-1);
	return (0);
}
