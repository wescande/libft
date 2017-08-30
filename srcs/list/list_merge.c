/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:45:04 by wescande          #+#    #+#             */
/*   Updated: 2017/08/30 13:46:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	list_merge(t_list *add, t_list *head)
{
	if (add != add->next)
	{
		add->next->prev = head;
		add->prev->next = head->next;
		head->next->prev = add->prev;
		head->next = add->next;
	}
}