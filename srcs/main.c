/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 07:56:58 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/26 07:57:00 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					expose_hook(t_cfg *cfg)
{
	mlx_destroy_image(cfg->mlx, cfg->img.img);
	cfg->img.img = mlx_new_image(cfg->mlx, WIDTH, HEIGHT);
	if (cfg->type == 0)
		julia(cfg);
	else if (cfg->type == 1)
		mandelbrot(cfg);
	mlx_clear_window(cfg->mlx, cfg->win);
	mlx_put_image_to_window(cfg->mlx, cfg->win, cfg->img.img, 0, 0);
	return (1);
}

char				ftype(int argc, char **argv)
{
	if (argc < 2)
		arg_error(0);
	if (argc > 2)
		arg_error(1);
	if (!ft_strcmp(argv[1], "j"))
		return (0);
	else if (!ft_strcmp(argv[1], "m"))
		return (1);
	else if (!ft_strcmp(argv[1], "p"))
		return (2);
	else
		arg_error(2);
	return (-1);
}

void				init_cfg(t_cfg *cfg, int argc, char **argv)
{
	cfg->mlx = mlx_init();
	cfg->win = mlx_new_window(cfg->mlx, WIDTH, HEIGHT, "Fractol");
	cfg->img.img = mlx_new_image(cfg->mlx, WIDTH, HEIGHT);
	cfg->img.data = mlx_get_data_addr(cfg->img.img, &cfg->img.bpp,
		&cfg->img.sl, &cfg->img.endian);
	cfg->type = ftype(argc, argv);
	cfg->iter = 50;
	cfg->cr = -0.75;
	cfg->ci = 0.27015;
	cfg->zoom = 1.0;
	cfg->theme = 0;
	cfg->themev = 0;
	cfg->offset = (t_dvec2){.x = 0.0, .y = 0.0};
	cfg->color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	init_sval(cfg);
}

int					main(int argc, char **argv)
{
	t_cfg			cfg;

	init_cfg(&cfg, argc, argv);
	mlx_put_image_to_window(cfg.mlx, cfg.win, cfg.img.img, 0, 0);
	mlx_hook(cfg.win, 2, 1, key_hook, &cfg);
	mlx_hook(cfg.win, 6, 64, &mouse, &cfg);
	mlx_expose_hook(cfg.win, expose_hook, &cfg);
	mlx_loop(cfg.mlx);
	return (0);
}
