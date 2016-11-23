/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:14:16 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 15:21:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_pow(int nb, int power)
{
	int					cpt;
	long long int		value;

	cpt = 1;
	value = nb;
	if (power > 0)
		while (cpt++ < power)
			value = value * nb;
	else
	{
		if (power == 0)
			value = 1;
		else
			value = 0;
	}
	return (value);
}
