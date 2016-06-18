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

void				put_pixel(t_img *img, t_vec2 p, t_color color)
{
	char			*pixel;

	if ((p.x < WIDTH && p.y < HEIGHT) && (p.x >= 0 && p.y >= 0))
	{
		pixel = img->data + p.y * img->sl + (img->bpp / 8) * p.x;
		pixel[2] = (int)(color.r * 256) % 256;
		pixel[1] = (int)(color.g * 256) % 256;
		pixel[0] = (int)(color.b * 256) % 256;
	}
}

void				draw_line_pta(t_img *img, t_vec2 a, t_vec2 b,
		t_color color)
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

void				draw_line_ptb(t_img *img, t_vec2 a, t_vec2 b,
		t_color color)
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

void				draw_line(t_cfg *cfg, t_vec2 a, t_vec2 b, t_color color)
{
	t_vec2			p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.x < 0 ? p.x = -p.x : p.x;
	p.y < 0 ? p.y = -p.y : p.y;
	if (p.x > p.y)
	{
		if (a.x <= b.x)
			draw_line_pta(&cfg->img, a, b, color);
		else
			draw_line_pta(&cfg->img, b, a, color);
	}
	else
	{
		if (a.y < b.y)
			draw_line_ptb(&cfg->img, a, b, color);
		else
			draw_line_ptb(&cfg->img, b, a, color);
	}
}
