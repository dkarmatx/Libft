/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:53:34 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/17 06:13:16 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# define MAX_LL 9223372036854775807
# define MAX_INT 2147483647
# define MAX_ULL 18446744073709551615

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_str_isnumeric(const char *str, int base);

#endif
