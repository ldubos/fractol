/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 07:57:20 by ldubos            #+#    #+#             */
/*   Updated: 2016/05/26 07:57:22 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				arg_error(int err)
{
	if (err == 0)
		ft_putendl_fd("\a\033[1;31;40mToo few arguments.\033[0m", 2);
	if (err == 1)
		ft_putendl_fd("\a\033[1;31;40mToo many arguments.\033[0m", 2);
	if (err == 2)
	{
		ft_putendl_fd("\a\033[1;31;40mBad argument(s).\033[0m", 2);
		ft_putendl_fd("\a\033[1;31;40m\tUse :\033[0m", 2);
		ft_putendl_fd("\a\033[1;31;40m\t\t-> 'j' | Julia\033[0m", 2);
		ft_putendl_fd("\a\033[1;31;40m\t\t-> 'm' | Mandelbrot\033[0m", 2);
		ft_putendl_fd("\a\033[1;31;40m\t\t-> 'p' | Placeholder\033[0m", 2);
	}
	exit(1);
}

void				malloc_error(void)
{
	ft_putendl_fd("\a\033[1;31;40mMemory error.\033[0m", 2);
	exit(1);
}
