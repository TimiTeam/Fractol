/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:55:28 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:56:49 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				my_fr(t_fract fr, int y, int x, int f(t_fract, int))
{
	int			n;

	n = fr.max_itr / 2 > 0 ? fr.max_itr / 2 : 2;
	return (f(fr, n) * (x + y));
}

void			*my_fract(void *p)
{
	t_fract		*fr;
	int			x;

	fr = (t_fract*)p;
	while (fr->y_s < fr->y_e)
	{
		x = 0;
		while (x < fr->size_x)
		{
			fr->d[x + fr->y_s * fr->size_x] = my_fr(*fr, fr->y_s, x, fr->col);
			x++;
		}
		fr->y_s++;
	}
	return (NULL);
}
