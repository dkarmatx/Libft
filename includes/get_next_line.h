/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:29:00 by hgranule          #+#    #+#             */
/*   Updated: 2019/09/02 16:43:58 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include "dstring.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
# endif

# ifndef FDS_MAX_LIMIT
#  define FDS_MAX_LIMIT 1000
# endif

int				get_next_line(const int fd, DSTRING **line);

#endif
