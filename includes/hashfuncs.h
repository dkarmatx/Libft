/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashfuncs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:15:41 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:10:50 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHFUNCS_H
# define HASHFUNCS_H

# include "ft_ctype.h"

# define HS_32_FNV_PRIME 0x01000193
# define HS_32_FNV_OFFSET 0x811C9DC5

# define HS_64_FNV_PRIME 0x00000100000001B3
# define HS_64_FNV_OFFSET 0XCBF29CE484222325

# define HS_DJB_OFFSET 0x1505

t_u64		hs_fnv1a_64(char const *str);
t_u32		hs_fnv1a_32(char const *str);
t_u64		hs_djb2_64(char const *str);

#endif
