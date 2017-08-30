/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 09:58:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:22:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#define ATOMIC_WRITE_BARRIER() __asm("" ::: "memory")

typedef struct		s_lx
{
	struct s_lx		*next;
	struct s_lx		*prev;
}					t_lx;

#define LIST_HEAD(name)			t_lx name = { &(name), &(name) }
#define INIT_LIST_HEAD(ptr)		(ptr)->next = (ptr)->prev = (ptr)

/*
** list_entry - get the struct for this entry
** @p:	the &struct list_head pointer.
** @t:	the type of the struct this is embedded in.
** @m:	the name of the list_struct within the struct.
*/
# define LIST_ENTRY_U(p,t,m)	((t *)((char *)(p) - offsetof(t, m)))
# define CHECK_0(p,t,m)			const typeof(((t *)0)->m) *__mptr = (p)
# define LIST_ENTRY(p,t,m)		CHECK_0(p,t,m);LIST_ENTRY_U(__mptr,t,m)
# define CONTAINER_OF(p,t,m)		LIST_ENTRY(p,t,m)


#define LIST_FOR_EACH(p, h)		p = (h); while ((p = p->next) != (h))
#define LIST_FOR_EACH_REV(p, h)	p = (h); while ((p = p->prev) != (h))

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
# define LFEE0(p,h,m)						p = LIST_ENTRY(h, typeof(*p), m)
# define LFEE1(p,m)				(p = LIST_ENTRY_U(p->m.next, typeof(*p), m))
# define LIST_FOR_EACH_ENTRY(p,h,m)		LFEE0(p,h,m);while(LFEE1(p,m) != (h))

/*
** list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
** @p:	the type * to use as a loop counter.
** @t:	another type * to use as temporary storage
** @h:	the head for your list.
** @m:	the name of the list_struct within the struct.
*/
# define LFS0(p,t,h,m)	LFEE0(p,h,m); t = LIST_ENTRY(p->m.next, typeof(*p), m)
# define LFS1(p,t,h,m)						({p = t; LFEE1(t,m);p->m;}) != (h)
# define LIST_FOR_EACH_ENTRY_SAFE(p,t,h,m)	LFS0(p,t,h,m);while(LFS1(p,t,h,m));


inline int		list_empty(t_lx *head);

inline void		list_add(t_lx *elem, t_lx *head);
inline void 	list_del_only(t_lx *prev, t_lx *next);
inline void		list_del(t_lx *elem);
inline void		list_del_init(t_lx *elem);

inline void		list_merge_only(t_lx *add, t_lx *head);
inline void		list_merge(t_lx *add, t_lx *head);

inline void		list_insert(t_lx *new, t_lx *prev, t_lx *next);
inline void		list_add_tail(t_lx *new, t_lx *head);


#endif