/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:14:04 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/26 09:14:05 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define SPEED 0.05
#define ITER_SPEED 5
#define ZOOM_SPEED 1.1

void				key_listener(int keycode, t_cfg *cfg )
{
	key_event(cfg, keycode);
	if (keycode == 123)
		cfg->offset.x -= SPEED / cfg->zoom;
	if (keycode == 124)
		cfg->offset.x += SPEED / cfg->zoom;
    if (keycode == 115 && cfg->theme < 6)
        cfg->theme += 1;
    if (keycode == 119 && cfg->theme > 0)
        cfg->theme -= 1;
    if (keycode == 67 && cfg->themev < 1)
        cfg->themev += 1;
    if (keycode == 75 && cfg->themev > 0)
        cfg->themev -= 1;
}

int					key_hook(int keycode, t_cfg *cfg)
{
	key_listener(keycode, cfg);
	expose_hook(cfg);
	return (0);
}

int                 mouse(int x, int y, t_cfg *cfg)
{
	cfg->cr = scaledx(cfg, x);
    cfg->ci = scaledy(cfg, y);
	expose_hook(cfg);
	return (1);
}

int					expose_hook(t_cfg *cfg)
{
/*
**	mlx_destroy_image(cfg->mlx, cfg->img);
**	mlx_clear_window(cfg->mlx, cfg->win);
**	cfg->img.img = mlx_new_image(cfg->mlx, WIDTH, HEIGHT);
*/
	if (cfg->type == 0)
		julia(cfg);
	else if (cfg->type == 1)
		mandelbrot(cfg);
	else if (cfg->type == 2)
		newton(cfg);
	gui_event(cfg);
	infos_event(cfg);
	if (display_infos)
		infos_event(cfg);
	mlx_put_image_to_window(cfg->mlx, cfg->win, cfg->img.img, 0, 0);
}
