/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:09:27 by hgranule          #+#    #+#             */
/*   Updated: 2019/05/02 22:18:30 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are initialized by copy
** of the parameters of the function. If the parameter content is nul, the
** variable content is initialized to NULL and the variable content_size is
** initialized to 0 even if the parameter content_size isn’t.
** The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
** Takes as a parameter a link’s pointer address and frees the
** memory of the link’s content using the function del given as
** a parameter, then frees the link’s memory using free(3). The
** memory of next must not be freed under any circumstance.
** Finally, the pointer to the link that was just freed must be
** set to NULL (quite similar to the function memdel in the
** mandatory part).
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter the adress of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to
** the link that was just freed must be set to NULL (quite similar
** to the function memdel from the mandatory part).
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
** Adds the element new at the beginning of the list.
*/
void				ft_lstadd(t_list **alst, t_list *new_lst);
/*
** Iterates the list lst and applies the function f to each link.
*/
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
