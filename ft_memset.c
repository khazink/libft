/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:02:46 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/17 17:33:45 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
