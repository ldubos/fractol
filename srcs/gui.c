/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 07:57:30 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/26 07:57:33 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				draw_line_pta(t_img *img, t_vec3 a, t_vec3 b,
		int color)
{
	t_vec2			p;

	p.x = a.x;
	while (p.x < b.x)
	{
		p.y = a.y + ((b.y - a.y) * (p.x - a.x)) / (b.x - a.x);
		put_pixel(img, p, color);
		++p.x;
	}
}

void				draw_line_ptb(t_img *img, t_vec3 a, t_vec3 b,
		int color)
{
	t_vec2			p;

	p.y = a.y;
	while (p.y < b.y)
	{
		p.x = a.x + ((b.x - a.x) * (p.y - a.y)) / (b.y - a.y);
		put_pixel(img, p, color);
		++p.y;
	}
}

void				draw_line(t_conf *conf, t_vec3 a, t_vec3 b, int color)
{
	t_vec2			p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.x < 0 ? p.x = -p.x : p.x;
	p.y < 0 ? p.y = -p.y : p.y;
	if (p.x > p.y)
	{
		if (a.x <= b.x)
			draw_line_pta(&conf->img, a, b, color);
		else
			draw_line_pta(&conf->img, b, a, color);
	}
	else
	{
		if (a.y < b.y)
			draw_line_ptb(&conf->img, a, b, color);
		else
			draw_line_ptb(&conf->img, b, a, color);
	}
}

void				draw_obj(t_conf conf)
{
	t_obj			*tmp;

	tmp = conf.obj;
	while (tmp != NULL)
	{
		if (tmp->c_vertex.y != 0)
			draw_line(&conf, iso(conf, tmp->c_vertex),
			iso(conf, tmp->p_vertex->c_vertex),
			get_color(tmp->c_vertex, tmp->p_vertex->c_vertex));
		if (tmp->next != NULL && tmp->next->c_vertex.y == tmp->c_vertex.y)
			draw_line(&conf, iso(conf, tmp->c_vertex),
			iso(conf, tmp->next->c_vertex),
			get_color(tmp->c_vertex, tmp->next->c_vertex));
		tmp = tmp->next;
	}
}
