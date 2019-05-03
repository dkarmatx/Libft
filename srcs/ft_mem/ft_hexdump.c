/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:44:34 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 21:37:17 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_hexdump(void *ptr, size_t size)
{
	unsigned char	*byte;
	int				fd;

	fd = 1;
	byte = (unsigned char *)ptr;
	while (size--)
	{
		if (*byte < 16)
			ft_putchar_fd('0', fd);
		ft_putll_base_fd(*byte, fd, 16);
		ft_putchar_fd(' ', fd);
		byte++;
	}
}
