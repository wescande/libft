/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 09:58:05 by wescande          #+#    #+#             */
/*   Updated: 2017/10/18 22:37:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <atomic.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct	s_lx
{
	struct s_lx		*next;
	struct s_lx		*prev;
}				t_lx;

# define LIST_HEAD_INIT(name)	{&(name), &(name)}
# define LIST_HEAD(name)		t_lx name = LIST_HEAD_INIT(name)
# define INIT_LIST_HEAD(p)		({(p)->prev = (p); WRITE_ONCE((p)->next, p);})

/*
** list_entry - get the struct for this entry
** @p:	the &struct list_head pointer.
** @t:	the type of the struct this is embedded in.
** @m:	the name of the list_struct within the struct.
*/
# define LIST_ENTRY_U(p,t,m)	((t *)((char *)(p) - offsetof(t, m)))

# define CHECK_0(p,t,m)			const typeof(((t *)0)->m) *__mptr = (p)
# define CONTAINER_OF(p,t,m)	({CHECK_0(p,t,m);LIST_ENTRY_U(__mptr,t,m);})
# define LIST_ENTRY(p,t,m)		CONTAINER_OF(p,t,m)

# define LIST_FIRST_ENTRY(p,t,m)	LIST_ENTRY((p)->next, t, m)
# define LIST_LAST_ENTRY(p,t,m)		LIST_ENTRY((p)->prev, t, m)

# define LIST_NEXT_ENTRY(p,m)	LIST_ENTRY_U((p)->m.next, typeof(*(p)), m)
# define LIST_PREV_ENTRY(p,m)	LIST_ENTRY_U((p)->m.prev, typeof(*(p)), m)

# define LIST_FOR_EACH(p, h)		p = (h); while ((p = p->next) != (h))
# define LIST_FOR_EACH_REV(p, h)	p = (h); while ((p = p->prev) != (h))

# define LFES0(p,t,h)						p = (h); t = p->next
# define LFES1(p,t,h)						({p = t; t = p->next; p;}) != (h)
# define LIST_FOR_EACH_SAFE(p,t,h)			LFES0(p,t,h); while(LFES1(p,t,h))

# define LFERS0(p,t,h)						p = (h); t = p->prev
# define LFERS1(p,t,h)						({p = t; t = p->prev; p;}) != (h)
# define LIST_FOR_EACH_REV_SAFE(p,t,h)		LFERS0(p,t,h); while(LFERS1(p,t,h))

/*
** list_for_each_entry - iterate over list of given type
** @p:	the type * to use as a loop counter.
** @h:	the head for your list.
** @m:	the name of the list_struct within the struct.
*/
# define LFEE0(p,h,m)					p = LIST_ENTRY(h, typeof(*p), m)
# define LFEE1(p,m)						&((p = LIST_NEXT_ENTRY(p,m))->m)
# define LFEE2(p,m)						&((p = LIST_PREV_ENTRY(p, m))->m)
# define LIST_FOR_EACH_ENTRY_0(p,h,m)	(LFEE0(p,h,m))
# define LIST_FOR_EACH_ENTRY_1(p,h,m)	(LFEE1(p,m) != (h))
# define LIST_FOR_EACH_ENTRY_REV_1(p,h,m)	(LFEE2(p,m) != (h))

/*
** for norme friendly :
** LIST_FOR_EACH_ENTRY_0(p,h,m);
** while(LIST_FOR_EACH_ENTRY_1(p,h,m))
** define LIST_FOR_EACH_ENTRY(p,h,m)	LFEE0(p,h,m); while(LFEE1(p,m) != (h))
** while(LIST_FOR_EACH_ENTRY_REV_1(p,h,m))
** define LIST_FOR_EACH_ENTRY_REV(p,h,m) LFEE0(p,h,m); while(LFEE2(p,m) != (h))
*/
# define LIST_FOR_EACH_ENTRY_FROM(p,h,m)		while(LFEE1(p,m) != (h))
# define LIST_FOR_EACH_ENTRY_FROM_REV(p,h,m)	while(LFEE2(p,m) != (h))

/*
** list_for_each_entry_safe -
** iterate over list of given type safe against removal of list entry
** @p:	the type * to use as a loop counter.
** @t:	another type * to use as temporary storage
** @h:	the head for your list.
** @m:	the name of the list_struct within the struct.
*/
# define LFS0(p,t,h,m)						LFEE0(p,h,m);t=LIST_NEXT_ENTRY(p,m)
# define LFS1(p,m)							(p = LIST_NEXT_ENTRY(p,m))
# define LFS2(p,t,h,m)						({p = t;LFS1(t,m);&(p->m);}) != (h)
# define LIST_FOR_EACH_ENTRY_SAFE_0(p,t,h,m)	LFS0(p,t,h,m)
# define LIST_FOR_EACH_ENTRY_SAFE_1(p,t,h,m)	LFS2(p,t,h,m)

/*
** Norme friendly hack
**# define LIST_FOR_EACH_ENTRY_SAFE(p,t,h,m) LFS0(p,t,h,m); while(LFS2(p,t,h,m))
*/

extern void		list_insert(t_lx *new_lx, t_lx *prev, t_lx *next);
extern void		list_add(t_lx *elem, t_lx *head);
extern void		list_add_tail(t_lx *new_lx, t_lx *head);

extern void		list_cut_position(t_lx *list, t_lx *head, t_lx *entry);

extern void		list_del_only(t_lx *prev, t_lx *next);
extern void		list_del(t_lx *elem);
extern void		list_del_init(t_lx *elem);

extern int		list_empty(const t_lx *head);
extern int		list_empty_careful(const t_lx *head);

extern int		list_is_last(const t_lx *list, t_lx *head);

extern int		list_is_singular(const t_lx *head);

extern void		list_merge(t_lx *add, t_lx *head);
extern void		list_merge_init(t_lx *add, t_lx *head);

extern void		list_move(t_lx *elem, t_lx *head);
extern void		list_move_tail(t_lx *elem, t_lx *head);

extern void		list_replace(t_lx *old, t_lx *new_lx);
extern void		list_replace_init(t_lx *old, t_lx *new_lx);

extern void		list_rotate_left(t_lx *head);

extern void		list_splice(const t_lx *list, t_lx *head);
extern void		list_splice_tail(t_lx *list, t_lx *head);
extern void		list_splice_init(t_lx *list, t_lx *head);
extern void		list_splice_tail_init(t_lx *list, t_lx *head);

extern t_lx		*list_findat(t_lx *head, size_t n);

extern size_t	list_len(t_lx *head);

#endif
