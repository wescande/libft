/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:42:21 by wescande          #+#    #+#             */
/*   Updated: 2017/11/22 11:45:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_tabcpy(char **av)
{
	int		len;
	char	**tab;
	int		i;

	len = ft_tablen(av);
	if (!(tab = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(tab[i] = ft_strdup(av[i])))
		{
			while (i--)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
	}
	tab[i] = NULL;
	return (tab);
}
