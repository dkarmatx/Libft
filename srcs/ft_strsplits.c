/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <hgranule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 01:37:58 by hgranule          #+#    #+#             */
/*   Updated: 2019/11/20 17:18:31 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static unsigned int	ft_countw_delims(char const *s, char const *delim)
{
	unsigned int	i;
	unsigned int	count;
	unsigned char	f_word;

	i = 0;
	f_word = 0;
	count = 0;
	if (s && delim)
		while (s[i])
		{
			if (ft_strchr(delim, (int)s[i]) || !(s[i]))
				if (f_word)
					f_word = 0;
			if (!(ft_strchr(delim, (int)s[i])) && s[i])
				if (!f_word)
				{
					count++;
					f_word = 1;
				}
			i++;
		}
	return (count);
}

static unsigned int	wordend(char const *s, char const *c, unsigned int i)
{
	while (s[i] && !(ft_strchr(c, (int)s[i])))
		i++;
	return (i);
}

static char			**abort_split(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = 0;
	return (tab);
}

static void			init(unsigned int *i, unsigned int *w, unsigned int *j)
{
	*i = 0;
	*w = 0;
	*j = 0;
}

char				**ft_strsplits(char const *s, char const *c)
{
	unsigned int	tablen;
	unsigned int	i;
	unsigned int	w;
	unsigned int	j;
	char			**tab;

	init(&i, &w, &j);
	if (!s)
		return (0);
	tablen = ft_countw_delims(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (tablen + 1))) != 0)
	{
		tab[tablen] = 0;
		while (w < tablen)
			if (ft_strchr(c, (int)s[i]))
				i++;
			else
			{
				j = wordend(s, c, i);
				if ((tab[w++] = ft_strsub(s, i, j - i)) == 0)
					return (abort_split(tab));
				i = j;
			}
	}
	return (tab);
}
