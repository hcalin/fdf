/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:22:39 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 17:32:06 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		valid_map(char **stk, int **k, char **tab)
{
	t_aux		s;
	int			*aux;
	size_t		i;
	int			sz;

	s.j = -1;
	sz = 0;
	aux = (int*)malloc(sizeof(int) * (**k) + 5);
	while (++s.j < (**k))
	{
		i = -1;
		while (++i < ft_strlen(stk[s.j]))
			if (!valid_aux(stk[s.j][i], stk[s.j][i + 1]))
				return (0);
		tab = ft_strsplit(stk[s.j], ' ');
		i = -1;
		s.numerator = 0;
		while (tab[++i])
			s.numerator++;
		if (!check_cols(aux, sz))
			return (0);
		else
			aux[sz++] = s.numerator;
	}
	return (1);
}

int		**chrtoint(char **stk, int **mat, int **i, int **sz)
{
	int		j;
	int		x;
	char	**tab;

	j = -1;
	tab = NULL;
	mat = (int**)malloc(sizeof(int*) * (**i) + 1);
	if (!valid_map(stk, i, tab))
	{
		ft_putstr("Map error\n");
		exit(1);
	}
	while (++j < (**i))
	{
		mat[j] = (int*)malloc(sizeof(int) * ft_count_words(stk[j], ' ') + 2);
		tab = ft_strsplit(stk[j], ' ');
		x = -1;
		while (tab[++x])
		{
			mat[j][x] = ft_atoi(tab[x]);
		}
		free(tab);
	}
	**sz = x;
	return (mat);
}

int		**readmat(int fd, int **mat, int *i, int *sz)
{
	char *line;
	char **stk;

	line = NULL;
	*i = 0;
	line = (char*)malloc(1000);
	stk = (char**)malloc(sizeof(char*) * 100);
	while ((*sz = get_next_line(fd, &line)) > 0)
	{
		*(stk + *i) = ft_strdup(line);
		free(line);
		(*i)++;
		line = (char*)malloc(1000);
	}
	*(stk + *i) = NULL;
	mat = chrtoint(stk, mat, &i, &sz);
	return (mat);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**mat;
	t_env	e;

	if (argc != 2)
	{
		printf("Usage: ./fdf <Filename>");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	mat = NULL;
	mat = readmat(fd, mat, &e.width, &e.length);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1024, 728, "42@FDF");
	env_init(mat, &e);
	parallel(e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
