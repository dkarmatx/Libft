/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_trim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:40:33 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/08 15:50:32 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"
#include "ft_string.h"

DSTRING		*dstr_trim(DSTRING *dstr)
{
	char	*trimmed;
	DSTRING	*trm_dstr;

	trimmed = ft_strtrim(dstr->txt);
	if (!trimmed)
		return (NULL);
	trm_dstr = dstr_new(trimmed);
	free(trimmed);
	return (trm_dstr);
}

void		dstr_trim_this(DSTRING **dstr)
{
	DSTRING	*dstr_trm;

	dstr_trm = dstr_trim(*dstr);
	dstr_del(dstr);
	*dstr = dstr_trm;
}