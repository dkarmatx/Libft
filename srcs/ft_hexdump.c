/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:44:34 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/06 09:34:24 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdio.h>

void	putheader(unsigned char *ptr)
{
	int		i;

	i = 16;
	printf("               X: ");
	while (i--)
	{
		printf("0%.1lx ", ((size_t)(ptr)) % 0x10);
		++ptr;
	}
	printf("\n\n");
}

void	*putrow(void *ptr)
{
	unsigned char	*byte;
	int				i;

	i = 16;
	printf("0x%.13lxX: ", ((size_t)ptr) / 0x10);
	byte = ptr;
	while (i--)
		printf("%.2hhX ", *byte++);
	i = 16;
	byte = ptr;
	printf("   ");
	while (i--)
	{
		if (*byte > 32 && *byte < 127)
			printf("%c", *byte);
		else
			printf(".");
		++byte;
	}
	printf("\n");
	return ((void *)byte);
}

void	dbg_snap_mem(void *ptr, size_t size)
{
	size_t			rows;

	rows = size / 16 + 1;
	putheader(ptr);
	while (rows--)
		ptr = putrow(ptr);
}

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
