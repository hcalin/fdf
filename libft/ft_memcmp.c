#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int 		i;
	unsigned char 		*str1;
	unsigned char 		*str2;

	if (!s1 && !s2 && !n)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (str1[i] == str2[i] && i <= n)
	{
		i++;
		if (i == (unsigned int)n || (!str1[i] && !str2[i]))
			return (0);
	}
	return (str1[i] - str2[i]);
}
