/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_ivents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:53:09 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 21:34:05 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_move(int x, int y, t_win *w)
{
	if (w->move && w->f == print_julia && w->in)
	{
		w->c_re = w->cp_r + (x - w->c_x) / 1000;
		w->c_im = w->cp_i + (y - w->c_y) / 1000;
		guess_buttom(0, w);
	}
	return (0);
}

int				stop_move(int key, t_win *w)
{
	if (key == 49 && w->move == 1)
		w->move = 0;
	else if (key == 49 && w->move == 0)
		w->move = 1;
	return (0);
}

int				mouse_ivent(int key, int x, int y, t_win *w)
{
	if ((key == 5 || key == 1) && w->z < ZOOM_SIZE && w->in)
	{
		w->m_x += (x - w->c_x) / w->move_ar[w->z];
		w->m_y += (y - w->c_y) / w->move_ar[w->z];
		w->z++;
		w->zoom = w->zoom_ar[w->z];
	}
	else if ((key == 4 || key == 2) && w->z > 0 && w->in)
	{
		w->m_x += (x - w->c_x) / w->move_ar[w->z];
		w->m_y += (y - w->c_y) / w->move_ar[w->z];
		w->z--;
		w->zoom = w->zoom_ar[w->z];
	}
	guess_buttom(0, w);
	return (0);
}
