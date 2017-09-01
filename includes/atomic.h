/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 10:23:32 by wescande          #+#    #+#             */
/*   Updated: 2017/09/01 11:58:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOMIC_H
# define ATOMIC_H

# define WRITE_ONCE(var, val)	(*((volatile typeof(val) *)(&(var))) = (val))
# define READ_ONCE(var)			(*((volatile typeof(var) *)(&(var))))

# define ATOMIC_WRITE_BARRIER() __asm("" ::: "memory")

#endif
