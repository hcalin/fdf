#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;
	size_t	len1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(dest);
	ptr = (char*)malloc(ft_strlen(src) + len1 + 5);
	while (*dest)
		ptr[i++] = *dest++;
	while (src[j])
		ptr[i++] = src[j++];
	ptr[i] = '\0';
	return (ptr);
}
