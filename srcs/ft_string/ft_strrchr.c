/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 08:31:40 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:33:47 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t		str_len;
	char		*finder;
	char		chr;

	str_len = ft_strlen(str);
	finder = (char *)(str + str_len);
	str_len += 1;
	chr = (char)ch;
	while (str_len--)
	{
		if (*finder == chr)
			return (finder);
		finder--;
	}
	return (0);
}
