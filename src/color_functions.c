/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:16:25 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:19:21 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				get_position(t_win w, int m)
{
	if (w.col == get_color && !m)
		return (715);
	if (w.col == mix_colors && !m)
		return (765);
	if (w.col == color_three && !m)
		return (835);
	if (w.c == 1)
		return (260);
	if (w.c == 2)
		return (290);
	if (w.c == 3)
		return (320);
	return (20);
}

void			guess_color(int key, t_win *w)
{
	if (key == 18 || key == 83)
	{
		w->c = 1;
		w->col = get_color;
	}
	else if ((key == 19 || key == 84) && w->f)
		w->col = mix_colors;
	else if ((key == 20 || key == 85) && w->f)
		w->col = color_three;
	else if (key == 8)
	{
		if (w->c >= 0 && w->c < 3)
			w->c++;
		else
			w->c = 0;
	}
}

int				mix_colors(t_fract fr, int itr)
{
	int			r;
	int			g;
	int			b;
	double		t;

	t = (double)itr / (double)fr.max_itr;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (65536 * r + 256 * g + b);
}

int				color_three(t_fract fr, int itr)
{
	int			r;
	int			g;
	int			b;

	r = 0;
	g = 0;
	b = 0;
	if (itr != fr.max_itr)
	{
		r = 5 * (itr * 2);
		g = 5 * (itr * 2);
		b = 5 * (itr * 2);
	}
	return (65536 * r + 256 * g + b);
}

int				get_color(t_fract fr, int itr)
{
	int			r;
	int			g;
	int			b;

	r = 0;
	g = 0;
	b = 0;
	if (itr == 0)
		return (65536 * (r * 2) + 256 * (g * 2) + (b * 2));
	if (itr == fr.max_itr)
		return (0);
	g = ((fr.g + itr * 2) * itr) < 255 ? fr.g + itr * 2 : fr.g;
	b = ((fr.b + itr * 2) * itr) < 255 ? fr.b + itr * 2 : fr.b;
	r = ((fr.r + itr * 2) * itr) < 255 ? fr.r + itr * 2 : fr.r;
	return (65536 * (r * itr) + 256 * (g * itr) + (b * itr));
}
