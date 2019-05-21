/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:59:45 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:34:56 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s)
	{
		if ((j = ft_strlen(s)))
		{
			j--;
			while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i <= j)
				i++;
			while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && i <= j)
				j--;
		}
		return (ft_strsub(s, i, j - i + 1));
	}
	return (0);
}
