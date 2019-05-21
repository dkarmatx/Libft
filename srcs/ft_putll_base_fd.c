/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll_base_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:02:05 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:20:20 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static long long	get_max_dec(long long nb, int base)
{
	long long dec;

	dec = 1;
	nb < 0 ? nb *= -1 : nb;
	while ((dec * base < nb) && (dec * base > 0))
		dec *= base;
	return (dec);
}

void				ft_putll_base_fd(long long nb, int fd, int base)
{
	long long		dec;
	int				cur;
	char			*alph;

	alph = "0123456789abcdefghijklmnopqrstuv";
	dec = get_max_dec(nb, base);
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	while (dec > 0)
	{
		if ((cur = nb / dec) == base)
			write(fd, "10", 2);
		else
			write(fd, &(alph[cur]), 1);
		nb %= dec;
		dec /= base;
	}
}
