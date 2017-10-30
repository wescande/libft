/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:15:43 by wescande          #+#    #+#             */
/*   Updated: 2017/10/26 16:54:24 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	verbose_only(const int level, const char *str)
{
	if (level == MSG_ERROR)
		ft_dprintf(2, "{pur}%s: {red}%s{eoc}\n", g_argv[0], str);
	else if (level == MSG_SUCCESS)
		ft_printf("{pur}%s: {gre}%s{eoc}\n", g_argv[0], str);
	else if (level == MSG_WARNING)
		ft_printf("{pur}%s: {yel}WARNING:{eoc} %s{eoc}\n", g_argv[0], str);
	else if (level == MSG_INFO)
		ft_printf("{pur}%s: {blu}INFO:{eoc} %s{eoc}\n", g_argv[0], str);
	else if (level == MSG_STD)
		ft_printf("{pur}%s: {eoc}%s{eoc}\n", g_argv[0], str);
	else if (level == MSG_DEBUG)
		ft_printf("{pur}%s: {YEL}{bla}DEBUG:{eoc} {yel}%s{eoc}\n",
				g_argv[0], str);
}

int			verbose(uint64_t flag, const int level, const char *message, ...)
{
	va_list		va;
	char		*str;

	if ((IS_SET(flag, QUIET) && level < MSG_DEBUG) ||
	(IS_UNSET(flag, DEBUG) && level == MSG_DEBUG) ||
	(IS_UNSET(flag, VERBOSE) && (level == MSG_INFO ||
		level == MSG_WARNING)))
		return (0);
	va_start(va, message);
	ft_vasprintf(&str, message, va);
	verbose_only(level, str);
	free(str);
	return ((level == MSG_ERROR) * -1);
}
