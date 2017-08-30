/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:25:43 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:20:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_empty - tests whether a list is empty
** @head: the list to test.
*/
inline int list_empty(t_lx *head)
{
	return (head->next == head);
}