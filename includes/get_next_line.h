/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:29:00 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/24 07:42:17 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFF_SIZE
# 	define BUFF_SIZE 1000
# endif

typedef	struct	s_fcache
{
	int		fd;
	size_t	size;
	char	*mem;
}				t_fcache;

int				get_next_line(const int fd, char **line);

#endif
