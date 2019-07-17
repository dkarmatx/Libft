/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:30:04 by hgranule          #+#    #+#             */
/*   Updated: 2019/07/17 19:23:55 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*str;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	str = ft_strsub(s1, 0, len);
	return (str);
}
