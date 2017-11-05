/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:13:52 by wescande          #+#    #+#             */
/*   Updated: 2017/11/05 23:37:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/* #include "tclInt.h" */
/* #include "tclPort.h" */

/*
 * The table below is used to convert from ASCII digits to a
 * numerical equivalent.  It maps from '0' through 'z' to integers
 * (100 for non-digit characters).
 */

static const char g_cvtin[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,		/* '0' - '9' */
	100, 100, 100, 100, 100, 100, 100,		/* punctuation */
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,	/* 'A' - 'Z' */
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35,
	100, 100, 100, 100, 100, 100,		/* punctuation */
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,	/* 'a' - 'z' */
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35};

/*
 *----------------------------------------------------------------------
 *
 * strtoul --
 *
 *	Convert an ASCII string into an integer.
 *
 * Results:
 *	The return value is the integer equivalent of string.  If endPtr
 *	is non-NULL, then *endPtr is filled in with the character
 *	after the last one that was part of the integer.  If string
 *	doesn't contain a valid integer value, then zero is returned
 *	and *endPtr is set to string.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

static uint64_t			convert_random(const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	register uint64_t		result;
	const uint64_t			maxres = UINT64_MAX  / base;
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
		unsigned long maxres = ULONG_MAX / base;
		for ( ; ; p += 1) {
			digit = *p - '0';
			if (digit > ('z' - '0')) {
				break;
			}
			digit = g_cvtin[digit];
			if (digit >= ( (unsigned) base )) {
				break;
			}
			if (result > maxres) { overflow = 1; }
			result *= base;
			if (digit > (ULONG_MAX - result)) { overflow = 1; }
			result += digit;
			anyDigits = 1;
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

static uint64_t			base_convert(const uint8_t base, const char *p,
									uint8_t *overflow, uint8_t *anydigits)
{
	if (base == 8)
		return (convert_octal(p, overflow, anydigits));
	else if (base == 10)
		return (convert_decimal(p, overflow, anydigits));
	else if (base == 16)
		return (convert_hexadecimal(p, overflow, anydigits));
	return (convert_random(p, overflow, anydigits));
	else if ( base >= 2 && base <= 36 ) {
		unsigned long maxres = ULONG_MAX / base;
		for ( ; ; p += 1) {
			digit = *p - '0';
			if (digit > ('z' - '0')) {
				break;
			}
			digit = g_cvtin[digit];
			if (digit >= ( (unsigned) base )) {
				break;
			}
			if (result > maxres) { overflow = 1; }
			result *= base;
			if (digit > (ULONG_MAX - result)) { overflow = 1; }
			result += digit;
			anyDigits = 1;
		}
	}
}

static uint8_t			base_check(uint8_t *base, const char **p)
{
	if (*base == 0)
	{
		if (**p == '0')
		{
			++*p;
			if ((**p == 'x') || (**p == 'X'))
			{
				++*p;
				*base = 16;
			}
			else
			{
				*base = 8;
				return (1);
			}
		}
		else
			*base = 10;
	}
	else if (*base == 16)
		if (((*p)[0] == '0') && (((*p)[1] == 'x') || ((*p)[1] == 'X')))
			*p += 2;
	return (0);
}

uint64_t				strtoul(const char *string, char **endptr, uint8_t base)
{
	register const char		*p;
	uint8_t					negative;
	uint8_t					anydigits;
	register uint64_t		result;
	uint8_t					overflow;

	p = string;
	negative = 0;
	while (ft_isspace(*p))
		++p;
	if (*p == '-' || *p == '+')
	{
		negative = *p == '-';
		++p;
	}
	anydigits = base_check(&base, &p);
	result = base_convert(base, p, &overflow, &anydigits);
	/*
	 * Sorry this code is so messy, but speed seems important.  Do
	 * different things for base 8, 10, 16, and other.
	 */

	/*
	 * See if there were any digits at all.
	 */

	if (!anyDigits) {
		p = string;
	}

	if (endPtr != 0) {
		/* unsafe, but required by the strtoul prototype */
		*endPtr = (char *) p;
	}

	if (overflow) {
		errno = ERANGE;
		return ULONG_MAX;
	} 
	if (negative) {
		return -result;
	}
	return result;
}