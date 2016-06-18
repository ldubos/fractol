/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:59:49 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/01 21:20:01 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	while (1)
		if (*s == c)
			return ((char *)s);
		else if (*s++ == '\0')
			return (NULL);
}
