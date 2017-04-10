/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:20:14 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 17:31:34 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_aux(char c, char d)
{
	if ((!ft_isdigit(c) && c != ' '))
	{
		if (c == '-' && ft_isdigit(d))
		{
			;
		}
		else
			return (0);
	}
	return (1);
}

int		check_cols(int *aux, int sz)
{
	int i;
	int j;

	i = 0;
	while (i < sz - 1)
	{
		j = i + 1;
		while (j < sz)
		{
			if (aux[j] != aux[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	env_init(int **mat, t_env *e)
{
	e->array = mat;
	e->x_offset = 350;
	e->y_offset = 100;
	e->x_origin = 0;
	e->y_origin = 0;
	e->height = 5;
	e->x_finish = 400;
	e->y_finish = 400;
	e->dx = 30;
	e->dy = 30;
}
