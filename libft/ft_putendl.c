#include "libft.h"

void	ft_putendl(char const *s)
{
	char ln;

	ln = '\n';
	ft_putstr(s);
	write(1, &ln, 1);
}
