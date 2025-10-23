/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:57:14 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/23 10:55:58 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			total_size;
	size_t			i;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
		total_size = 1;
	else
		total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
