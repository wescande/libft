/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 00:01:08 by wescande          #+#    #+#             */
/*   Updated: 2017/08/28 00:29:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_test.h>

t_itof	g_fun[] = 
{
	{1, test_memset},
	{0, 0},
};

int ft_putnstr(const char *str, size_t n)
{
	return (write(1, str, n));
}

int		main(void)
{
	int i = -1;
	while (g_fun[++i].id)
		if (g_fun[i].f())
			return (1);
	return (0);
}
