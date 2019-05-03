/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:14:39 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:26:38 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_atoi_base(const char *str, int base)
{
	long long		over;
	int				cast;

	over = ft_atoll_base(str, base);
	cast = (int)over;
	return (cast);
}
