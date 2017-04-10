#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *ptr;
	unsigned char x;

	i = 0;
	if (n == 0)
		return (s);
	ptr = (unsigned char*)s;
	x = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = x;
		i++;
	}
	return (ptr);
}
