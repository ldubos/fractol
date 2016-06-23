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

void				button(t_cfg *cfg, t_rec rec, char *label, t_color color)
{
	int				y;
	unsigned int	len;

	y = rec.a.y;
	len = ft_strlen(label);
	while (y > rec.b.y)
	{
		draw_line(cfg, rec.a, (t_vec2){rec.b.x, rec.a.y}, color);
	}
	mlx_string_put(cfg->mlx, cfg->win, rec.a.x + 10,
		(sqrt((rec.b.y - rec.a.y) * (rec.b.y - rec.a.y)) / 2), 0xFFFFFF, label);
}
