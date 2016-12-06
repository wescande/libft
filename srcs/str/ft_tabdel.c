/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:35:54 by wescande          #+#    #+#             */
/*   Updated: 2016/12/06 11:39:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	char	**erase;
	int		i;

	erase = *tab;
	i = 0;
	while (erase[i])
	{
		ft_strdel(&erase[i]);
		++i;
	}
	free(*tab);
	*tab = NULL;
}
