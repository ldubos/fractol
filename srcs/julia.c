/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 08:12:11 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/26 08:12:12 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void                algo_julia(t_cfg *cfg, int x, int y)
{
    double          ncr;
    double          nci;
    double          ocr;
    double          oci;
    int             index;

    ncr = 1.5 * (x - WIDTH / 2) / (0.5 * cfg->zoom * WIDTH) + cfg->offset.x;
    nci = (y - HEIGHT / 2) / (0.5 * cfg->zoom * HEIGHT) + cfg->offset.y;
    index = 0;
    while (index < cfg->iter)
    {
        ocr = ncr;
        oci = nci;
        ncr = ocr * ocr - oci * oci + cfg->ci;
        nci = 2 * ocr * oci + cfg->ci;
        if((ncr * ncr + nci * nci) > 4)
            break;
        ++index;
    }
    cfg->color = palette(index, cfg->theme, cfg->themev);
    put_pixel(&cfg->img, (t_vec2){x, y}, cfg->color);
}

void                julia(t_cfg *cfg)
{
    int             x;
    int             y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            algo_julia(cfg, x, y);
            ++x;
        }
        ++y;
    }
}
