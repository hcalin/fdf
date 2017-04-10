#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	int		i;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dest);
}
