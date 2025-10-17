/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:38:46 by kkaman            #+#    #+#             */
/*   Updated: 2025/10/17 16:25:36 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strdup(const char *s)
{
	char	*ptr;
	int	len;

	if (s == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		ptr[len] = s[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
