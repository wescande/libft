/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 09:58:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/30 14:20:30 by wescande         ###   ########.fr       */
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

#define CHECK_TYPE(p, t, m)		const typeof(((t *)0)->m) *__mptr = (p)
#define DELTA(t, m)				(t *)((char *)__mptr - offsetof(t, m))

#define LIST_ENTRY(p, t, m)		((t *)((char *)(p) - (size_t)(&((t *)0)->m)))


#define LIST_FOR_EACH(p, h)		for (p = (h)->next; p != (h); p = p->next)
#define LIST_FOR_EACH(p, h)		p = (h); while ((p = p->next) != (h))

#define LIST_FOR_EACH_REV(p, h) for (p = (h)->prev; p != (h); p = p->prev)
#define LIST_FOR_EACH_REV(p, h)	p = (h); while ((p = p->prev) != (h))

void	list_add(t_lx *elem, t_lx *head);
void	list_del(t_lx *elem);
void	list_del(t_lx *elem);

#endif




 
#ifndef _LIST_H
#define _LIST_H        1
 
/* Internal: doubly linked lists.  */
 
/* The definitions of this file are adopted from those which can be
   found in the Linux kernel headers to enable people familiar with
   the latter find their way in these sources as well.  */
 
#include <list_t.h>
#include <atomic.h>
 
/* Iterate forward over the elements of the list.  */
#define list_for_each(pos, head) \
  for (pos = (head)->next; pos != (head); pos = pos->next)
 
/* Iterate forward over the elements of the list.  */
#define list_for_each_prev(pos, head) \
  for (pos = (head)->prev; pos != (head); pos = pos->prev)
 
/* Iterate backwards over the elements list.  The list elements can be
   removed from the list while doing this.  */
#define list_for_each_prev_safe(pos, p, head) \
  for (pos = (head)->prev, p = pos->prev; \
       pos != (head); \
       pos = p, p = pos->prev)
 
#endif        /* list.h */