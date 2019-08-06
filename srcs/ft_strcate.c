/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:37:01 by hgranule          #+#    #+#             */
/*   Updated: 2019/08/06 07:11:04 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcate(char *s1, const char *s2)
{
	size_t	s1_len;
	size_t  s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ft_strcpy(&(s1[s1_len]), s2);
	return (s1_len + s2_len + s1);
}
