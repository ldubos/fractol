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

t_color				palette(double x, int theme, int themev)
{
	t_color			color;

	if (themev == 0)
	{
		color.r = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 0 || theme == 3 ||
		theme == 5));
		color.g = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 1 || theme == 3 ||
		theme == 4));
		color.b = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 2 || theme == 4 ||
		theme == 5));
	}
	if (themev == 1)
	{
		color.r = 0.5 + 0.5 * cos(8.0 + x * 0.15 + (theme == 0 || theme == 3 ||
		theme == 5));
		color.g = 0.5 + 0.5 * cos(3.0 + x * 0.1 + (theme == 1 || theme == 3 ||
		theme == 4));
		color.b = 0.5 + 0.5 * cos(4.0 + x * 0.35 + (theme == 2 || theme == 4 ||
		theme == 5));
	}
	return (color);
}

void				init_sval(t_cfg *cfg)
{
	if (cfg->type == 0)
	{
		cfg->xbot = -2.5;
		cfg->xtop = 1;
		cfg->ybot = -1;
		cfg->ytop = 1;
	}
	else if (cfg->type == 1)
	{
		cfg->xbot = -2;
		cfg->xtop = 2;
		cfg->ybot = -2;
		cfg->ytop = 2;
	}
	else if (cfg->type == 2)
	{
		cfg->xbot = -4;
		cfg->xtop = 4;
		cfg->ybot = -4;
		cfg->ytop = 4;
		cfg->xs = WIDTH / 2;
	}
}

double				scaledy(t_cfg *cfg, int y)
{
	double			dy;

	dy = (((cfg->ytop - cfg->ybot) * y) / HEIGHT) + cfg->ybot;
	return (dy);
}

double				scaledx(t_cfg *cfg, int x)
{
	double			dx;

	dx = (((cfg->xtop - cfg->xbot) * x) / HEIGHT) + cfg->xbot;
	return (dx);
}
