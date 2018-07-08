/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:06:33 by wescande          #+#    #+#             */
/*   Updated: 2018/07/08 18:06:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	**ft_tabdup(void **av)		
{
    int		len;
    void	**tab;
    
    len = ft_tablen(av);
    if (!(tab = (void **)malloc(sizeof(void *) * len + 1)))
        return (NULL);
    return (ft_tabcpy(tab, av));
}