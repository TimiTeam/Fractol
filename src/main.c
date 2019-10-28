/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:45:16 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:50:56 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				check_i(int i)
{
	if (i == 23 || i == 44 || i == 70 || i == 98)
		return (1);
	if (i == 118 || i == 143 || i == 167 || i == 194)
		return (1);
	if (i == 215 || i == 245 || i == 265 || i == 285 || i == 290)
		return (1);
	return (0);
}

void			make_zoom_buf(t_win *w)
{
	int			i;
	double		z;
	long int	m_f;

	i = 0;
	z = 1;
	m_f = 1;
	while (i < ZOOM_SIZE)
	{
		w->zoom_ar[i] = z;
		w->move_ar[i] = 10000 * m_f;
		z += z < 2 ? 0.1 : z / 10;
		if (check_i(i))
			m_f *= 10;
		i++;
	}
	w->zoom_ar[i] = z += z < 2 ? 0.1 : z / 10;
	w->move_ar[i] = m_f * 10;
	w->z = 0;
}

int				make_main_struct(t_win *win)
{
	if (!(win->mlx = mlx_init()))
		return (0);
	win->size_x = 1300;
	win->size_y = 1000;
	win->title = ft_strdup("Fractol");
	if (!(win->ptr = mlx_new_window(win->mlx,
					win->size_x, win->size_y, win->title)))
		return (0);
	win->max_itr = 51;
	win->zoom = 1;
	win->m_x = 0;
	win->m_y = 0;
	win->c_re = -0.4;
	win->c_im = -0.59;
	win->cp_r = win->c_re;
	win->cp_i = win->c_im;
	win->col = mix_colors;
	win->c_x = win->size_x / 2;
	win->c_y = win->size_y / 2;
	win->step = win->size_y / THREADS;
	win->r = 68;
	win->g = 0;
	win->b = 10;
	win->c = 0;
	return (1);
}

char			**make_string_arr(char *path)
{
	int			fd;
	int			i;
	char		**all;
	char		*line;

	if (!(all = (char**)malloc(sizeof(char*) * 15 + 1)))
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		all[i] = ft_strdup(line);
		free(line);
		i++;
	}
	all[i] = 0;
	return (all);
}

int				main(int ac, char **av)
{
	t_win		*win;

	win = NULL;
	if (ac == 2)
	{
		win = (t_win*)malloc(sizeof(t_win));
		if (!make_main_struct(win))
			error_message(12, win);
		win->move = 1;
		win->h = 1;
		if (!(win->str_arr = make_string_arr("src/src.txt")))
			error_message(1, win);
		make_zoom_buf(win);
		if (!check_fract(av[1], win))
			error_message(2, win);
	}
	else
		error_message(22, win);
	mlx_hook(win->ptr, 17, 1L << 17, exit_x, win);
	mlx_hook(win->ptr, 3, 3, stop_move, win);
	mlx_hook(win->ptr, 2, 2, guess_buttom, win);
	mlx_mouse_hook(win->ptr, mouse_ivent, win);
	mlx_hook(win->ptr, 6, 6, mouse_move, win);
	mlx_loop(win->mlx);
	return (0);
}
