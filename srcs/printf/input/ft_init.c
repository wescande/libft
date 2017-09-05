/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:52:19 by wescande          #+#    #+#             */
/*   Updated: 2017/09/05 15:21:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			initialize_fun_bonus(t_wrk *w)
{
	w->fun[b] = &conv_b;
	w->fun[b_b] = &conv_b_b;
	w->fun[e] = &conv_e;
	w->fun[b_e] = &conv_b_e;
	w->fun[f] = &conv_f;
	w->fun[b_f] = &conv_b_f;
	w->fun[g] = &conv_g;
	w->fun[b_g] = &conv_b_g;
	w->fun[a] = &conv_a;
	w->fun[b_a] = &conv_b_a;
	w->fun[n] = &conv_n;
}

static void			initialize_fun(t_wrk *w)
{
	w->fun[s] = &conv_s;
	w->fun[b_s] = &conv_b_s;
	w->fun[p] = &conv_p;
	w->fun[d] = &conv_i;
	w->fun[b_d] = &conv_b_d;
	w->fun[i] = &conv_i;
	w->fun[o] = &conv_o;
	w->fun[b_o] = &conv_b_o;
	w->fun[u] = &conv_u;
	w->fun[b_u] = &conv_b_u;
	w->fun[x] = &conv_x;
	w->fun[b_x] = &conv_b_x;
	w->fun[c] = &conv_c;
	w->fun[b_c] = &conv_b_c;
	w->fun[n_fun] = &conv_unknow;
}

void				initialize_work(const char *str, t_wrk *w)
{
	w->buf = (char *)str;
	w->ans = NULL;
	w->len = 0;
	w->curlen = 0;
	initialize_fun(w);
	initialize_fun_bonus(w);
}
