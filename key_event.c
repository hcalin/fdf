/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:24:38 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 17:19:58 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	parallel(e[0]);
}

void	event_key(int keycode, t_env *e)
{
	if (keycode == 13)
		e->y_offset -= 50;
	if (keycode == 1)
		e->y_offset += 50;
	if (keycode == 0)
		e->x_offset -= 50;
	if (keycode == 2)
		e->x_offset += 50;
	if (keycode == 69)
	{
		e->dx += 3;
		e->dy += 3;
	}
	if (keycode == 78 && e->dx > 4)
	{
		e->dx -= 3;
		e->dy -= 3;
	}
	if (keycode == 3)
		e->height -= 7;
	if (keycode == 5)
		e->height += 7;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		printf("Pressed ESC key. Exit...\n");
		exit(1);
	}
	else
		event_key(keycode, *&e);
	expose_hook(e);
	return (0);
}
