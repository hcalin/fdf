/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:29:53 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 17:22:21 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		get_point(int x, int y, t_env e)
{
	t_point		p;
	int			cordx;
	int			cordy;

	cordx = e.x_offset + x * e.dx;
	cordy = e.y_offset + y * e.dy;
	p.z = e.array[y][x];
	p.x = cordx - cordy;
	if (p.z > 0)
	{
		p.y = (cordx + cordy) / 2 - (p.z + e.height);
		p.z += e.height;
	}
	else
	{
		p.y = (cordx + cordy) / 2 + (p.z + e.height);
		p.z -= e.height;
	}
	return (p);
}

void		fill_structure(t_env e, t_point *p)
{
	int		i;
	int		j;
	int		sz;

	i = -1;
	sz = 0;
	while (++i < e.width)
	{
		j = -1;
		while (++j < e.length)
			p[sz++] = get_point(j, i, e);
	}
}

void		parallel(t_env e)
{
	int			i;
	int			j;
	int			sz;
	t_point		*p;

	display_menu(e);
	p = (t_point*)malloc(sizeof(t_point) * e.width * e.length + 2);
	fill_structure(e, p);
	i = -1;
	sz = 0;
	while (++i < e.width)
	{
		j = -1;
		while (++j < e.length)
		{
			if (j < e.length - 1)
				draw(p[sz], p[sz + 1], e);
			if (i < e.width - 1)
				draw(p[sz], p[sz + e.length], e);
			sz++;
		}
	}
}
