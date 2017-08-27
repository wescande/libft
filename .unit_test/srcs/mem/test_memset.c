/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 00:15:39 by wescande          #+#    #+#             */
/*   Updated: 2017/08/28 00:39:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit_test.h>

int		test_memset(void)
{
	DG();
	char a = -1;
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	char *ret, *ret_cmp;
	int len = strlen(str);
	int result = 0;
	int i;

	while (++a < 127)
	{
		++result;
		ret_cmp = memset(str_cmp, a, 1);
		ret = ft_memset(str, a, 1);
		i = -1;
		++result;
		while (++i < len)
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				DG("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 5, a, 4);
		ret = ft_memset(str + 5, a, 4);
		++result;
		i = -1;
		while (++i < (len - 5))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				DG("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 2, a, len - 3);
		ret = ft_memset(str + 2, a, len - 3);
		++result;
		i = -1;
		while (++i < (len - 2))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				DG("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
	}
	return (0);
}