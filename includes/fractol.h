/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:33:47 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/11 17:33:49 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# include "libft.h"

# define WIDTH 800
# define HEIGHT 800

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;

}					t_img;

typedef struct		s_dvec2
{
	double			x;
	double			y;
}					t_dvec2;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_rec
{
	t_vec2			a;
	t_vec2			b;
}					t_rec;

typedef struct		s_button
{
	t_rec			rec;
	t_color			color;
	char			*label;
}					t_button;

typedef struct		s_cfg
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				theme;
	int				themev;
	char			type;
	int				iter;
	double			cr;
	double			ci;
	double			zoom;
	double			ytop;
	double			ybot;
	double			xtop;
	double			xbot;
	double			xs;
	t_dvec2			offset;
	t_color			color;
	char			active_mouse;
	char			display_infos;
	char			*mouse_label;
	t_color			mouse_color;
	t_vec2			mouse;
}					t_cfg;

/*
** error.c
*/

void				arg_error(int err);
void				malloc_error(void);

/*
** draw.c
*/

void				put_pixel(t_img *img, t_vec2 p, t_color color);
void				draw_line(t_cfg *cfg, t_vec2 a, t_vec2 b, t_color color);

/*
** basic_draw.c
*/

t_color				palette(double x, int theme, int themev);
void				init_sval(t_cfg *cfg);
double				scaledx(t_cfg *cfg, int x);
double				scaledy(t_cfg *cfg, int y);

/*
** julia.c
*/

void                julia(t_cfg *cfg);

/*
** mandelbrot.c
*/

void				mandelbrot(t_cfg *cfg);

/*
** event.c
*/

void				infos_event(t_cfg *cfg);
void				key_event(t_cfg *cfg, int keycode);

/*
** hook.c
*/

int					key_hook(int keycode, t_cfg *conf);
int                 mouse(int x, int y, t_cfg *cfg);
int					expose_hook(t_cfg *cfg);

#endif
