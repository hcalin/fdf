/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:16:46 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 14:50:06 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			display_menu(t_env e)
{
	mlx_string_put(e.mlx, e.win, 20, 20, 0xFFFFFF,
			"Use WASD controls to move the object");
	mlx_string_put(e.mlx, e.win, 20, 34, 0xFFFFFF, "Use +/- for Zoom");
	mlx_string_put(e.mlx, e.win, 20, 48, 0xFFFFFF,
			"Use F/G key to adjust the height");
}

t_aux			aux_init2(t_aux s)
{
	s.dx1 = 0;
	s.dy1 = 0;
	s.dx2 = 0;
	s.dy2 = 0;
	if (s.w < 0)
		s.dx1 = -1;
	else if (s.w > 0)
		s.dx1 = 1;
	if (s.h < 0)
		s.dy1 = -1;
	else if (s.h > 0)
		s.dy1 = 1;
	if (s.w < 0)
		s.dx2 = -1;
	else if (s.w > 0)
		s.dx2 = 1;
	return (s);
}

t_aux			aux_init(t_aux s)
{
	s = aux_init2(s);
	s.longest = abs(s.w);
	s.shortest = abs(s.h);
	if (!(s.longest > s.shortest))
	{
		s.longest = abs(s.h);
		s.shortest = abs(s.w);
		if (s.h < 0)
			s.dy2 = -1;
		else if (s.h > 0)
			s.dy2 = 1;
		s.dx2 = 0;
	}
	s.numerator = s.longest >> 1;
	return (s);
}

void			draw(t_point p1, t_point p2, t_env e)
{
	int		i;
	t_aux	s;

	s.w = p2.x - p1.x;
	s.h = p2.y - p1.y;
	s = aux_init(s);
	i = -1;
	while (++i <= s.longest)
	{
		mlx_pixel_put(e.mlx, e.win, p1.x, p1.y, get_color(p1, p2));
		s.numerator += s.shortest;
		if (!(s.numerator < s.longest))
		{
			s.numerator -= s.longest;
			p1.x += s.dx1;
			p1.y += s.dy1;
		}
		else
		{
			p1.x += s.dx2;
			p1.y += s.dy2;
		}
	}
}

int				get_color(t_point p1, t_point p2)
{
	int		z;
	int		color;

	if (p2.z > p1.z)
		z = p2.z;
	else
		z = p1.z;
	if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xE0D3CC;
	else
		color = 0;
	return (color);
}
