#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlittle;

	i = 0;
	j = 0;
	nlittle = ft_strlen(little);
	if (nlittle == 0)
		return ((char *)big);
	while (big[i] && i < len - 1)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			if (j == nlittle - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
