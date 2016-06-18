/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:49:38 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/01 17:46:32 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *s)
{
	char			sign;
	int				r;

	sign = 1;
	r = 0;
	while ((*s == '\n' || *s == ' ' || *s == '\v' || *s == '\t' || *s == '\r' ||
			*s == '\f') && *s)
		++s;
	if (*s == '-')
	{
		sign = -1;
		++s;
	}
	else if (*s == '+')
		++s;
	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		r = r * 10 + (*s - '0');
		++s;
	}
	return (r * sign);
}