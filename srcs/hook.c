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
