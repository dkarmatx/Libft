/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:17:35 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/03 06:34:04 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static unsigned int	wordend(char const *s, char c, unsigned int i)
{
	while (s[i] && s[i] != c)
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

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	tablen;
	unsigned int	i;
	unsigned int	w;
	unsigned int	j;
	char			**tab;

	init(&i, &w, &j);
	tab = 0;
	tablen = ft_countw_delim(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (tablen + 1))) != 0)
	{
		tab[tablen] = 0;
		while (w < tablen)
			if (s[i] == c)
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
