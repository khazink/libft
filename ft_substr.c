#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (*ptr = '\0', ptr);
	}
	if (len > s_len - start)
		len = s_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < len)
		ptr[i] = s[start + i];
	return (ptr[i] = '\0', ptr);
}
