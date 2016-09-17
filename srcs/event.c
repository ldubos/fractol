/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  event.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:32:13 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 09:02:52 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				infos_event(t_cfg *cfg)
{
	button(cfg, (t_rec){(t_vec2){250, 10}, (t_vec2){350, 60}},
		ft_strjoin("Iterations : ", ft_itoa(cfg->iter)),
		(t_color){0.0, 0.0, 0.0});
	button(cfg, (t_rec){(t_vec2){250, 70}, (t_vec2){350, 60}},
		ft_strjoin("Iterations : ", ft_itoa(cfg->iter)),
		(t_color){0.0, 0.0, 0.0});
}

void				key_event(t_cfg *cfg, int keycode)
{
	if (keycode == 53)
    {
        mlx_destroy_window(cfg->mlx, cfg->win);
		exit(EXIT_SUCCESS);
    }
	if (keycode == 69)
		cfg->zoom *= ZOOM_SPEED;
	if (keycode == 78)
		cfg->zoom /= ZOOM_SPEED;
	if (keycode == 116)
		cfg->iter += ITER_SPEED;
	if (keycode == 121)
		cfg->iter -= ITER_SPEED;
	if (keycode == 126)
		cfg->offset.y -= SPEED / cfg->zoom;
	if (keycode == 125)
		cfg->offset.y += SPEED / cfg->zoom;
}