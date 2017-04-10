#include "libft.h"

void	ft_putendl_fd(char const *s,int fd)
{
	unsigned int i;
	char ln;

	i = 0;
	ln = '\n';
	while (s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
	write(fd, &ln, 1);
}
