/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:49:08 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/23 10:42:01 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	cal_len(const char *input)
{
	size_t	i;

	i = 0;
	while (input[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = cal_len(src);
	d_len = cal_len(dst);
	if (size <= d_len)
		return (d_len + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i) < size - 1)
	{
		dst[i + d_len] = src[i];
		i++;
	}
	dst[i + d_len] = '\0';
	return (d_len + s_len);
}
