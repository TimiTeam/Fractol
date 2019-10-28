/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_sheep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:13:00 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:15:58 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				calc_ship(t_fract *fr, double new_re,
		double new_im, int f(t_fract, int))
{
	double		old_re;
	double		old_im;
	int			itr;

	itr = 0;
	while (itr < fr->max_itr)
	{
		old_im = new_im;
		old_re = new_re;
		new_re = old_re * old_re - old_im * old_im + fr->c_re;
		new_im = 2 * fabs(old_re * old_im) + fr->c_im;
		if (new_im * new_im + new_re * new_re > 4)
			break ;
		itr++;
	}
	return (f(*fr, itr));
}

void			*print_ship(void *par)
{
	t_fract		*fr;
	int			x;

	fr = (t_fract*)par;
	while (fr->y_s < fr->y_e)
	{
		fr->c_im = (fr->y_s - fr->cen_y) / (0.6 * fr->zoom_y) + fr->m_y;
		x = 0;
		while (x < fr->size_x)
		{
			fr->c_re = (x - fr->cen_x) / (0.6 * fr->zoom_x) + fr->m_x;
			fr->d[x + fr->y_s * fr->size_x] = calc_ship(fr, 0, 0, fr->col);
			x++;
		}
		fr->y_s++;
	}
	return (NULL);
}
