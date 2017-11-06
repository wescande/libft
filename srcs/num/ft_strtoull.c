/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:13:52 by wescande          #+#    #+#             */
/*   Updated: 2017/11/06 14:31:22 by tempow_wi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**----------------------------------------------------------------------
** .
** ft_strtoul --
** .
** Convert an ASCII string into an integer.
** .
** Results:
** The return value is the integer equivalent of string.  If endPtr
** is non-NULL, then *endPtr is filled in with the character
** after the last one that was part of the integer.  If string
** doesn't contain a valid integer value, then zero is returned
** and *endPtr is set to string.
** .
** Side effects:
** None.
** .
** ----------------------------------------------------------------------
*/
static const char		*base_check(uint8_t *base, uint8_t	*anydigits,
									const char *p)
{
	if (*base == 0)
	{
		if (*p == '0')
		{
			++p;
			if ((*p == 'x') || (*p == 'X'))
			{
				++p;
				*base = 16;
			}
			else
			{
				*base = 8;
				*anydigits = 1;
				return (p);
			}
		}
		else
			*base = 10;
	}
	else if (*base == 16)
		if ((p[0] == '0') && ((p[1] == 'x') || (p[1] == 'X')))
			p += 2;
	*anydigits = 0;
	return (p);
}

uint64_t				ft_strtoull(const char *string,
									char **endptr, uint8_t base)
{
	register const char		*p;
	uint8_t					negative;
	uint8_t					anydigits;
	register uint64_t		result;
	uint8_t					overflow;

	p = string;
	while (ft_isspa(*p))
		++p;
	negative = *p == '-';
	if (*p == '-' || *p == '+')
		++p;
	p = base_check(&base, &anydigits, p);
	result = base_convert(base, p, &overflow, &anydigits);
	if (!anydigits)
		p = string;
	if (endptr)
		*endptr = (char *) p;
	if (overflow)
		return (UINT64_MAX);
	if (negative)
		return (-result);
	return (result);
}