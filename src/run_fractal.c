/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:57:12 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 21:43:28 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract				*make_fract(t_win *w, int from, int step)
{
	t_fract			*fr;

	fr = (t_fract*)malloc(sizeof(t_fract));
	fr->d = w->d;
	fr->y_s = from;
	fr->y_e = from + step;
	fr->size_x = w->size_x;
	fr->size_y = w->size_y;
	fr->c_re = w->c_re;
	fr->c_im = w->c_im;
	fr->m_x = w->m_x;
	fr->m_y = w->m_y;
	fr->max_itr = w->max_itr;
	fr->col = w->col;
	fr->r = w->r;
	fr->g = w->g;
	fr->b = w->b;
	fr->zoom_x = w->zoom_x;
	fr->zoom_y = w->zoom_y;
	fr->cen_x = w->c_x;
	fr->cen_y = w->c_y;
	return (fr);
}

int					run_thread(t_win *w)
{
	t_fract			*frcts[THREADS];
	pthread_t		thread[THREADS];
	int				i;

	w->img = mlx_new_image(w->mlx, w->size_x, w->size_y);
	w->d = (int*)mlx_get_data_addr(w->img, &w->bi, &w->l, &w->en);
	w->zoom_x = 0.5 * w->zoom * w->size_x;
	w->zoom_y = 0.5 * w->zoom * w->size_y;
	i = -1;
	while (++i < THREADS)
	{
		frcts[i] = make_fract(w, i * w->step, w->step);
		pthread_create(&thread[i], NULL, w->f, frcts[i]);
	}
	i = -1;
	while (++i < THREADS)
	{
		pthread_join(thread[i], NULL);
		free(frcts[i]);
	}
	mlx_put_image_to_window(w->mlx, w->ptr, w->img, 0, 0);
	free(w->img);
	free(w->d);
	return (0);
}
