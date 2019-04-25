/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:53:29 by hgranule          #+#    #+#             */
/*   Updated: 2019/04/10 03:24:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		preview_print_hex(unsigned char *ptr, int size)
{
	unsigned char	*p;
	int				i;
	int				fd;

	i = 0;
	fd = 1;
	p = ptr;
	while (i < size)
	{
		ft_putstr_fd("   ", fd);
		if (p[i] < 16)
			ft_putchar_fd('0', fd);
		ft_putll_base_fd(p[i++], fd, 16);
		ft_putstr_fd(" ", fd);
	}
	ft_putstr_fd(" ", fd);
}

static void		preview_print_dec(unsigned char *ptr, int size)
{
	unsigned char	*p;
	int				i;
	int				fd;

	i = 0;
	fd = 1;
	p = ptr;
	while (i < size)
	{
		ft_putstr_fd("  ", fd);
		if (p[i] < 10)
			ft_putchar_fd('0', fd);
		if (p[i] < 100)
			ft_putchar_fd('0', fd);
		ft_putll_base_fd(p[i++], fd, 10);
		ft_putstr_fd(" ", fd);
	}
	ft_putstr_fd(" ", fd);
}

static void		preview_print_empty(unsigned char *ptr, int size)
{
	unsigned char	*p;
	int				i;
	int				fd;

	i = -1;
	fd = 1;
	p = ptr;
	ft_putstr_fd("\n", fd);
	while (++i < size)
	{
		ft_putstr_fd("  ___ ", fd);
	}
	ft_putstr_fd(" \n", fd);
}

static void		preview_print_char(unsigned char *ptr, int size)
{
	unsigned char	*p;
	int				i;
	int				fd;

	i = -1;
	fd = 1;
	p = ptr;
	while (++i < size)
	{
		ft_putstr_fd("  ", fd);
		if (ft_isascii(p[i]))
			if (ft_isprint(p[i]))
			{
				ft_putstr_fd(" ", fd);
				ft_putchar_fd((char)p[i], fd);
				ft_putstr_fd("  ", fd);
			}
			else
				ft_putstr_fd("... ", fd);
		else
			ft_putstr_fd(",,, ", fd);
	}
	ft_putstr_fd(" ", fd);
	ft_putstr_fd("\n\n\n", fd);
}

void			ft_print_bytes(void *ptr, int size)
{
	unsigned char	*p;
	int				i;
	int				fd;

	fd = 1;
	i = -1;
	p = ptr;
	preview_print_empty(p, size);
	preview_print_dec(p, size);
	preview_print_empty(p, size);
	preview_print_hex(p, size);
	preview_print_empty(p, size);
	preview_print_char(p, size);
	while (++i < size)
	{
		ft_putstr_fd("Byte #", fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd("\nhis adress 0x", fd);
		ft_putll_base_fd((unsigned long long)(&(p[i])), fd, 16);
		ft_putstr_fd("\nbase 02 :: ", fd);
		ft_putll_base_fd(p[i], fd, 2);
		ft_putstr_fd("\nbase 10 :: ", fd);
		ft_putll_base_fd(p[i], fd, 10);
		ft_putstr_fd("\n\n", fd);
	}
}
