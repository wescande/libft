/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 22:58:17 by wescande          #+#    #+#             */
/*   Updated: 2017/10/05 12:01:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	g_error_msglist[E_MAX][ERRMSG_MAX_SIZE] =
{
	"Unknown error 0",
	"Invalid option -%c",
	"Invalid option --%s",
	"Option '%c' awaits argument(s): please don't combine",
	"Option '%c': missing argument",
	"Option '%s': missing argument",
	"%s: no such file or directory",
	"%s: Is a directory",
	"%s: Permission denied",
	"Option '%c': not a valid argument",
	"Option '%s': not a valid argument",
	"Error: Memory allocation error",
	"%s: Failed to open file: %s",
	"%s: %s",
};

int		g_errnum = 0;
char	*g_errmsg = NULL;
char	**g_argv;

int		error_set(int n, ...)
{
	va_list	ap;

	g_errnum = n;
	va_start(ap, n);
	ft_strdel(&g_errmsg);
	ft_vasprintf(&g_errmsg, g_error_msglist[n], ap);
	return (g_errnum);
}

int		ft_perror(char *utility)
{
	utility = utility ? utility : g_argv[0];
	ERR_MSG(utility, g_errmsg);
	return (g_errnum);
}

char	*ft_strerror(int errnum)
{
	if (errnum > E_MAX)
		return (g_error_msglist[0]);
	if (errnum == g_errnum)
		return (g_errmsg);
	return (g_error_msglist[errnum]);
}
