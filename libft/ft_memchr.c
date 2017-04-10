#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char	x;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char*)s;
	x = (unsigned char)c;
	while (n)
	{
		if(ptr[i] == x)
			return ((void*)(ptr + i));
		i++;
		n--;
	}
	return (0);
}
