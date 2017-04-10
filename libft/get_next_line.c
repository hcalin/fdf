#include "libft.h"

int	get_next_line(int  fd, char **line)
{
	static int	nx;
	char		*buff;
	
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!(buff = (char*)malloc(3)))
		return (-1);
	while ((nx = read(fd, buff, 1)))
	{
		if ( nx == -1)
			return (-1);
		if (buff[0] == '\n' && !*line)
		{
			*line = ft_strdup("\0");
			return (1);
		}
		else if(buff[0] == '\n')
			return (1);
		buff[1] = '\0';
		if (!*line && buff[0])
			*line = ft_strdup(buff);
		else
			*line = ft_strjoin(*line,buff);
		if (!buff[0] && !*line)
			return (0);
		else if (!buff[0])
			return (1);
	}
	return	(nx);
}
