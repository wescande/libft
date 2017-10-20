/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:43:14 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 12:09:25 by wescande         ###   ########.fr       */
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

static void		check_color_bg(t_wrk *w, char *end)
{
	if (!ft_strncmp(end, "{EOC}", 5))
		ft_strinsert_replace(w, DEF, end - w->ans, 5);
	else if (!ft_strncmp(end, "{BLA}", 5))
		ft_strinsert_replace(w, BG_BLACK, end - w->ans, 5);
	else if (!ft_strncmp(end, "{RED}", 5))
		ft_strinsert_replace(w, BG_RED, end - w->ans, 5);
	else if (!ft_strncmp(end, "{GRE}", 5))
		ft_strinsert_replace(w, BG_GREEN, end - w->ans, 5);
	else if (!ft_strncmp(end, "{YEL}", 5))
		ft_strinsert_replace(w, BG_YELLOW, end - w->ans, 5);
	else if (!ft_strncmp(end, "{BLU}", 5))
		ft_strinsert_replace(w, BG_BLUE, end - w->ans, 5);
	else if (!ft_strncmp(end, "{PUR}", 5))
		ft_strinsert_replace(w, BG_PURPLE, end - w->ans, 5);
	else if (!ft_strncmp(end, "{CYA}", 5))
		ft_strinsert_replace(w, BG_CYAN, end - w->ans, 5);
	else if (!ft_strncmp(end, "{WHI}", 5))
		ft_strinsert_replace(w, BG_WHITE, end - w->ans, 5);
}

static void		check_color_fg(t_wrk *w, char *end)
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
	else if (!ft_strncmp(end, "{inv}", 5))
		ft_strinsert_replace(w, INV, end - w->ans, 5);
	else
		check_color_bg(w, end);
}

void			ft_colorize(t_wrk *w)
{
	char	*end;

	while (w->len > 4 && (end = ft_strnchr(w->buf, '{', w->len - 5))
			&& end[4] == '}')
	{
		check_color_fg(w, end);
		w->len -= ((end - w->buf) + 1);
		w->buf = end + 1;
	}
}
