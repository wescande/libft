/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:43:14 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 20:19:59 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_strinsert_replace(t_wrk *w, char *in, int pos, int width)
{
	int	index;

	index = 0;
	while (index < width)
	{
		w->ans[pos + index] = in[index];
		++index;
	}
}

void			ft_colorize(t_wrk *w)
{
	char	*end;

	while ((end = ft_strchr(w->buf, '{')))
	{
		if (!ft_strncmp(end, "{eoc}", 5))
			ft_strinsert_replace(w, DEF, end - w->ans, 5);
		else if (!ft_strncmp(end, "{bla}", 5))
			ft_strinsert_replace(w, BLACK, end - w->ans, 5);
		else if (!ft_strncmp(end, "{red}", 5))
			ft_strinsert_replace(w, RED, end - w->ans, 5);
		else if (!ft_strncmp(end, "{gre}", 5))
			ft_strinsert_replace(w, GREEN, end - w->ans, 5);
		else if (!ft_strncmp(end, "{yel}", 5))
			ft_strinsert_replace(w, YELLOW, end - w->ans, 5);
		else if (!ft_strncmp(end, "{blu}", 5))
			ft_strinsert_replace(w, BLUE, end - w->ans, 5);
		else if (!ft_strncmp(end, "{pur}", 5))
			ft_strinsert_replace(w, PURPLE, end - w->ans, 5);
		else if (!ft_strncmp(end, "{cya}", 5))
			ft_strinsert_replace(w, CYAN, end - w->ans, 5);
		else if (!ft_strncmp(end, "{whi}", 5))
			ft_strinsert_replace(w, WHITE, end - w->ans, 5);
		w->buf = end + 1;
	}
}
