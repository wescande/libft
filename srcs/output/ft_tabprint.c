/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:01:36 by wescande          #+#    #+#             */
/*   Updated: 2016/12/21 13:59:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabprint(char **mytab)
{
	int		i;

	if (!mytab || !*mytab)
		return ;
	i = 0;
	while (mytab[i])
	{
		ft_putendl(mytab[i]);
		++i;
	}
}
