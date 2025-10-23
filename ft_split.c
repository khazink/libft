#include "libft.h"

int	word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

char	*word_dup(const

char	**ft_split(char const *s, char c)
{
//count how many words
	while(s[i] != '\0')
	{
		if (s[i] != c && in_word == 1)
			count++;
		i++;
	}
}
