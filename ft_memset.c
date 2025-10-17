/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:02:46 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/12 12:05:32 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			m;
	unsigned char	*p;

	p = (unsigned char *)s;
	m = 0;
	while (m < n)
	{
		p[m] = (unsigned char)c;
		m++;
	}
	return (s);
}
