#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	vect[n];

	ft_memcpy(vect, s2, n);
	ft_memcpy(s1, vect, n);
	return (s1);
}
