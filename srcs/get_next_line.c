/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:28:29 by hgranule          #+#    #+#             */
/*   Updated: 2019/07/26 08:41:57 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static t_list	*fd_init(const int fd, t_list **db)
{
	t_fcache	newfd;
	t_fcache	*content;
	t_list		*file;

	newfd.fd = fd;
	newfd.mem = (void *)0;
	newfd.size = 0;
	if (fd < 0 && read(fd, 0, 0) < 0)
		return (0);
	if ((file = *db))
		while (file)
		{
			if ((content = (t_fcache *)file->content)->fd == fd)
				return (file);
			file = file->next;
		}
	if (!(file = ft_lstnew(&newfd, sizeof(t_fcache))))
		return (0);
	if (!(*db))
		*db = file;
	else
		ft_lstadd(db, file);
	return (file);
}

static int		cache_pull(t_fcache **cache, char **line)
{
	size_t	clen;
	char	*ccp;
	char	*tmp;

	if ((ccp = ft_memchr((*cache)->mem, '\n', (*cache)->size)) == 0)
		clen = (*cache)->size + 1;
	else
		clen = (ccp + 1) - (*cache)->mem;
	if ((*line = (char *)ft_realloc(*line, clen)) == (char *)0)
		return (-1);
	ft_memcpy(*line, (*cache)->mem, clen - 1);
	(*line)[clen - 1] = 0;
	if (ccp)
	{
		(*cache)->size -= clen;
		tmp = (char *)ft_memdup((*cache)->mem + clen, (*cache)->size);
		ft_memdel((void **)&((*cache)->mem));
		(*cache)->mem = tmp;
		return (0);
	}
	ft_memdel((void **)&((*cache)->mem));
	(*cache)->size = 0;
	return (1);
}

static int		read_n_push(t_fcache **cache, char **line)
{
	ssize_t		rmem;
	char		*tmp[3];
	char		buff[BUFF_SIZE + 1];

	while ((rmem = read((*cache)->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rmem] = 0;
		if (!(tmp[2] = ft_memchr(buff, '\n', rmem)))
			tmp[0] = ft_strjoin(*line, buff);
		else
		{
			*tmp[2] = 0;
			(*cache)->size = ft_strlen(tmp[2] + 1) + 1;
			if (!(tmp[0] = ft_strjoin(*line, buff))
			|| !(tmp[1] = ft_memdup(tmp[2] + 1, (*cache)->size)))
				return (-1);
			(*cache)->mem = tmp[1];
		}
		ft_memdel((void **)line);
		if ((*line = tmp[0]) == 0)
			return (-1);
		if (tmp[2])
			break ;
	}
	return (rmem);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*data_bank = 0;
	t_list				*file;
	t_fcache			*cache;
	int					state[2];

	if (!line)
		return (-1);
	*line = ft_strnew(0);
	state[0] = 1;
	state[1] = 0;
	if (!(file = fd_init(fd, &data_bank)))
		return (-1);
	cache = file->content;
	if ((cache->size))
		state[0] = cache_pull(&cache, line);
	if (state[0])
		state[1] = read_n_push(&cache, line);
	if (state[1] < 0)
		return (-1);
	if (cache->size == 0 && !state[1] && !(**line))
		return (0);
	return (1);
}
