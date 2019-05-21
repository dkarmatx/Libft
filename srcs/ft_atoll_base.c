/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:51:56 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:27:13 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_ctype.h"

static int		sign_checker(char **it)
{
	if (**it == '-')
	{
		(*it)++;
		return (-1);
	}
	else if (**it == '+')
	{
		(*it)++;
		return (1);
	}
	return (1);
}

static int		get_num_from_base(char c, int base)
{
	int		i;
	char	*alph;

	i = -1;
	alph = "0123456789abcdefghijklmnopqrstuv";
	while (++i < base)
		if (c == alph[i])
			return (i);
	return (-1);
}

long long		ft_atoll_base(const char *str, int base)
{
	long long		summ;
	long long		tmp;
	int				sign;
	char			*it;

	summ = 0;
	sign = 0;
	it = (char *)str;
	while (ft_isspace((int)(*it)))
		it++;
	sign = sign_checker(&it);
	while ((tmp = get_num_from_base(*it, base)) != -1)
	{
		summ = (summ * base) + tmp;
		it++;
		if ((summ > MAX_LL / base || summ == MAX_LL / base) && (*it - '0' > 0))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return ((long long)summ * sign);
}
