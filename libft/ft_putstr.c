#include <unistd.h>
#include "libft.h"

void	ft_putstr(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		write(1,&s[i],1);
		i++;
	}
}
