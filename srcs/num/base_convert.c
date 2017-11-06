/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tempow_wil <wescande@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:23:22 by tempow_wi         #+#    #+#             */
/*   Updated: 2017/11/06 13:57:47 by tempow_wi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** The table below is used to convert from ASCII digits to a
** numerical equivalent. It maps from '0' through 'z' to integers
** (100 for non-digit characters => error).
*/

static const uint8_t	 g_cvtin[] =
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	100, 100, 100, 100, 100, 100, 100,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35,
	100, 100, 100, 100, 100, 100,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35
};

static uint64_t			convert_random(const char *p, uint8_t *overflow,
		uint8_t *anydigits, uint8_t base)
{
	register uint64_t		result;
	const uint64_t			maxres = UINT64_MAX  / base;
	register uint8_t		digit;

	result = 0;
	while (*p)
	{
		digit = *p - '0';
		if (digit > ('z' - '0'))
			break;
		digit = g_cvtin[digit];
		if (digit >= base)
			break;
		if (result > maxres)
			*overflow = 1;
		result *= base;
		if (digit > (UINT64_MAX - result))
			*overflow = 1;
		result += digit;
		*anydigits = 1;
		++p;
	}
	return (result);
}

static uint64_t			convert_hexadecimal(const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	register uint64_t		result;
	const uint64_t			maxres = UINT64_MAX >> 4;
	register uint8_t		digit;

	result = 0;
	while (*p)
	{
		digit = *p - '0';
		if (digit > ('z' - '0'))
			break;
		digit = g_cvtin[digit];
		if (digit > 15)
			break;
		if (result > maxres)
			*overflow = 1;
		result = (result << 4);
		if (digit > (UINT64_MAX - result))
			*overflow = 1;
		result += digit;
		*anydigits = 1;
		++p;
	}
	return (result);
}

static uint64_t			convert_decimal(const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	register uint64_t		result;
	const uint64_t			maxres = UINT64_MAX / 10;
	register uint8_t		digit;

	result = 0;
	while (*p)
	{
		digit = *p - '0';
		if (digit > 9)
			break;
		if (result > maxres)
			*overflow = 1;
		result *= 10;
		if (digit > (UINT64_MAX - result))
			*overflow = 1;
		result += digit;
		*anydigits = 1;
		++p;
	}
	return (result);
}

static uint64_t			convert_octal(const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	register uint64_t		result;
	const uint64_t			maxres = UINT64_MAX >> 3;
	register uint8_t		digit;

	result = 0;
	while (*p)
	{
		digit = *p - '0';
		if (digit > 7)
			break;
		if (result > maxres)
			*overflow = 1;
		result = (result << 3);
		if (digit > (UINT64_MAX - result))
			*overflow = 1;
		result += digit;
		*anydigits = 1;
		++p;
	}
	return (result);
}

uint64_t			base_convert(const uint8_t base, const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	if (base == 8)
		return (convert_octal(p, overflow, anydigits));
	else if (base == 10)
		return (convert_decimal(p, overflow, anydigits));
	else if (base == 16)
		return (convert_hexadecimal(p, overflow, anydigits));
	return (convert_random(p, overflow, anydigits, base));
}

