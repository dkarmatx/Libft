/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:07:44 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:22:15 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t		mem;

	if (s)
	{
		mem = ft_strlen(s);
		write(fd, s, mem);
	}
}
