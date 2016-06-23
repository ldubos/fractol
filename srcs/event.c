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

/*
**	# Mouse Button :
**		* Color :
**			(t_color){15.0, 30.0, 200.0} 		# Active
**			(t_color){75.0, 15.0, 100.0}		# Desactive
**		* Label :
**			"Active"							# Active
**			"Desactive"							# Desactive
*/

void				gui_event(t_cfg *cfg)
{
	button(cfg, (t_rec){(t_vec2){10, 10}, (t_vec2){60, 120}}, "Fractal <",
		(t_color){255.0, 100.0, 50.0});
	button(cfg, (t_rec){(t_vec2){60, 130}, (t_vec2){70, 120}}, "Fractal >",
		(t_color){0.0, 255.0, 75.0});
	button(cfg, (t_rec){(t_vec2){10, 70}, (t_vec2){120, 120}}, "Theme -",
		(t_color){255.0, 100.0, 50.0});
	button(cfg, (t_rec){(t_vec2){130, 70}, (t_vec2){240, 120}}, "Theme +",
		(t_color){0.0, 255.0, 75.0});
	if (ft_strcmp(cfg->mouse_label, "Active"))
		button(cfg, (t_rec){(t_vec2){cfg->mouse.x -115, cfg->mouse.y - 25 },
			(t_vec2){cfg->mouse.x + 115, cfg->mouse.y + 25}},
			ft_strjoin(cfg->mouse_label, " mouse"), cfg->mouse_color);
	else
		button(cfg, (t_rec){(t_vec2){10, 130},
			(t_vec2){240, 180}},
			ft_strjoin(cfg->mouse_label, " mouse"), cfg->mouse_color);
}

void				gui_event_collider(t_cfg *cfg, int x, int y, int button)
{
	if (x >= 10 && x <= 120 && y >= 10 && y <= 60 && cfg->type > 0)
		--cfg->type;
	if (x >= 10 && x <= )
}

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