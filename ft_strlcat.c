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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	d_len = 0;
	while (d_len < size && dst[d_len] != '\0')
		d_len++;
	if (size == d_len)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i + 1) < size)
	{
		dst[i + d_len] = src[i];
		i++;
	}
	if (d_len + i < size)
		dst[i + d_len] = '\0';
	return (d_len + s_len);
}
