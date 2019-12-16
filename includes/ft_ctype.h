/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:53:34 by hgranule          #+#    #+#             */
/*   Updated: 2019/12/16 13:10:03 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef	unsigned int		t_u32;
typedef unsigned long long	t_u64;
typedef char				t_i8;
typedef short				t_i16;
typedef int					t_i32;
typedef long long			t_i64;

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
