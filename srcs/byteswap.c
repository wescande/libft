/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byteswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:46:32 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 12:33:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>

inline uint8_t		bswap_8(uint8_t x)
{
	return (x);
}

inline uint16_t		bswap_16(uint16_t x)
{
	return ((
				(x >> 8) & 0xffu) | (
				(x & 0xffu) << 8));
}

inline uint32_t		bswap_32(uint32_t x)
{
	return (((x & 0xff000000u) >> 24)
			| ((x & 0x00ff0000u) >> 8)
			| ((x & 0x0000ff00u) << 8)
			| ((x & 0x000000ffu) << 24));
}

inline uint64_t		bswap_64(uint64_t x)
{
	return (((x & 0xff00000000000000ull) >> 56)
			| ((x & 0x00ff000000000000ull) >> 40)
			| ((x & 0x0000ff0000000000ull) >> 24)
			| ((x & 0x000000ff00000000ull) >> 8)
			| ((x & 0x00000000ff000000ull) << 8)
			| ((x & 0x0000000000ff0000ull) << 24)
			| ((x & 0x000000000000ff00ull) << 40)
			| ((x & 0x00000000000000ffull) << 56));
}
