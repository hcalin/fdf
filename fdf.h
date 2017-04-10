/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:55:16 by chrihorc          #+#    #+#             */
/*   Updated: 2017/03/24 17:27:49 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**array;
	int		height;
	int		scale;
	int		nr_y;
	int		nr_x;
	int		x_offset;
	int		y_offset;
	int		x_origin;
	int		y_origin;
	int		x_finish;
	int		y_finish;
	int		width;
	int		length;
	int		dx;
	int		dy;
}				t_env;

typedef struct	s_aux
{
	int		j;
	int		w;
	int		h;
	int		dx1;
	int		dy1;
	int		dx2;
	int		dy2;
	int		longest;
	int		shortest;
	int		numerator;
}				t_aux;

int				get_next_line(int fd, char **line);
void			display_tab(t_env e);
void			env_init(int **mat, t_env *e);
void			draw(t_point p1, t_point p2, t_env e);
t_point			get_point(int x, int y, t_env e);
void			parallel(t_env e);
int				key_hook(int keycode, t_env *e);
void			event_key(int keycode, t_env *e);
void			display_menu(t_env e);
int				get_color(t_point p1, t_point p2);
void			fill_structure(t_env e, t_point *p);
t_aux			aux_init(t_aux s);
t_aux			aux_init2(t_aux s);
int				valid_map(char **stk, int **i, char **tab);
int				check_cols(int *aux, int sz);
int				valid_aux(char c, char d);
#endif
