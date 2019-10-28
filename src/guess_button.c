/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:39:05 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:41:48 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			key_plus_minus(int key, t_win *w)
{
	if (key == 69)
	{
		if (!w->c || w->col != get_color)
			w->max_itr += 5;
		else if (w->c == 1)
			w->r++;
		else if (w->c == 2)
			w->g++;
		else if (w->c == 3)
			w->b++;
	}
	else if (key == 78)
	{
		if ((!w->c || w->col != get_color) && w->max_itr > 5)
			w->max_itr -= 5;
		else if (w->c == 1 && w->r > 0)
			w->r--;
		else if (w->c == 2 && w->g > 0)
			w->g--;
		else if (w->c == 3 && w->b > 0)
			w->b--;
	}
}

void			reset_all(t_win *w)
{
	w->max_itr = 51;
	w->zoom = 1;
	w->m_x = 0;
	w->m_y = 0;
	w->c_re = w->cp_r;
	w->c_im = w->cp_i;
	w->r = 51;
	w->g = 0;
	w->b = 14;
	w->z = 0;
}

void			choose_fract(int key, t_win *w)
{
	if (key == JULIA)
		w->f = print_julia;
	else if (key == MANDELBROT)
		w->f = print_mandel;
	else if (key == BURNING_SHIP)
		w->f = print_ship;
	else if (key == TIMUR)
		w->f = my_fract;
	reset_all(w);
	w->in = 1;
}

void			move_key(int key, t_win *w)
{
	if (key == 123)
		w->m_x += (double)-100 / w->move_ar[w->z];
	else if (key == 124)
		w->m_x += (double)100 / w->move_ar[w->z];
	else if (key == 126)
		w->m_y += (double)-100 / w->move_ar[w->z];
	else if (key == 125)
		w->m_y += (double)100 / w->move_ar[w->z];
}

int				guess_buttom(int key, t_win *w)
{
	if (key == 53)
		exit_x(w);
	else if ((key >= 18 && key <= 20) || (key >= 83 && key <= 85))
		guess_color(key, w);
	else if (key == 38 || key == 11 || key == 17 || key == 46)
		choose_fract(key, w);
	else if (key == 69 || key == 78)
		key_plus_minus(key, w);
	else if (key == 12)
		set_options(w);
	else if (key == 15)
		reset_all(w);
	else if (key == 4)
	{
		if (w->h == 1)
			w->h = 0;
		else
			w->h = 1;
	}
	else if (key >= 123 && key <= 125)
		move_key(key, w);
	else if (key == 8 && w->col == get_color)
		guess_color(key, w);
	set_state(w);
	return (0);
}
