/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:39:44 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:27:46 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static long long	get_max_dec(long long nb, int base)
{
	long long dec;

	dec = 1;
	nb < 0 ? nb *= -1 : nb;
	while ((dec * base < nb) && (dec * base > 0))
		dec *= base;
	return (dec);
}

static size_t		count_ll_digits(long long nb, int base)
{
	int		count;

	count = 1;
	nb < 0 ? nb *= -1 : nb;
	while (nb > (base - 1))
	{
		nb /= base;
		count++;
	}
	return (count);
}

static void			push_number(char **number, long long nb, int base, int *i)
{
	long long	dec;
	int			cur;
	char		*alph;

	alph = "0123456789abcdefghijklmnopqrstuv";
	*i = 0;
	dec = get_max_dec(nb, base);
	if (nb < 0)
	{
		nb *= -1;
		(*number)[(*i)++] = '-';
	}
	while (dec > 0)
	{
		if ((cur = nb / dec) == base)
		{
			(*number)[(*i)++] = '1';
			(*number)[(*i)++] = '0';
		}
		else
			(*number)[(*i)++] = alph[cur];
		nb %= dec;
		dec /= base;
	}
}

char				*ft_lltoa_base(long long nb, int base)
{
	int			i;
	char		*number;

	i = count_ll_digits(nb, base);
	(nb < 0) ? i += 1 : i;
	number = (char *)malloc(sizeof(char) * (i + 1));
	if (number)
	{
		push_number(&number, nb, base, &i);
		number[i] = 0;
	}
	return (number);
}
