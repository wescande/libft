/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:08:29 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 13:49:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	index;

	if (!s || !f)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	index = 0;
	while (s[index])
	{
		fresh[index] = (*f)(s[index]);
		++index;
	}
	fresh[index] = '\0';
	return (fresh);
}
