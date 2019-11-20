/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 07:33:23 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:19:19 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_str_isnumeric(const char *str, int base)
{
	char	*ptr;
	size_t	i;
	int		a;

	if (!str || !(*str) || base > 16 || base < 2)
		return (0);
	i = 0;
	while (str[i])
	{
		ptr = ft_strchr("00112233445566778899AaBbCcDdEeFf", str[i]);
		a = (int)ptr - (int)str;
		if (a >= base)
			return (0);
		++i;
	}
	return (1);
}
