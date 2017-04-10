#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	nlen;

	i = 0;
	j = 0;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == nlen - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
