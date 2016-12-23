/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabprint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:03:28 by wescande          #+#    #+#             */
/*   Updated: 2016/12/21 13:58:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabprint_fd(char **mytab, int fd)
{
	int		i;

	if (!mytab || !*mytab)
		return ;
	i = 0;
	while (mytab[i])
	{
		ft_putendl_fd(mytab[i], fd);
		++i;
	}
}
