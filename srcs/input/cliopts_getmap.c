/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliopts_getmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 22:56:31 by wescande          #+#    #+#             */
/*   Updated: 2017/10/26 18:59:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cliopts	*cliopts_getmap_long(const t_cliopts opt_map[], char *arg)
{
	int		i;

	i = -1;
	while (opt_map[++i].c)
		if (!ft_strcmp(opt_map[i].str, arg))
			return ((t_cliopts *)&opt_map[i]);
	return (NULL);
}

t_cliopts	*cliopts_getmap_short(const t_cliopts opt_map[], char arg)
{
	int		i;

	i = -1;
	while (opt_map[++i].c)
		if (opt_map[i].c == arg)
			return ((t_cliopts *)&opt_map[i]);
	return (NULL);
}
