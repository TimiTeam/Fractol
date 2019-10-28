/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:32:26 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 21:22:40 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_state(t_win *w)
{
	mlx_clear_window(w->mlx, w->ptr);
	if (w->in)
		run_thread(w);
	else
		set_options(w);
	if (w->h)
		print_help(w);
}

int				colors_in_menu(t_win *w, int i)
{
	char		*c;
	int			n;

	c = ft_itoa(w->r);
	n = get_position(*w, 1);
	mlx_string_put(w->mlx, w->ptr, 500, 200, HEXW, w->str_arr[i++]);
	mlx_string_put(w->mlx, w->ptr, 500, 220, HEXW, w->str_arr[i]);
	mlx_string_put(w->mlx, w->ptr, 500, 260, HEXR, "R = ");
	mlx_string_put(w->mlx, w->ptr, 610, 260, HEXR, c);
	free(c);
	c = ft_itoa(w->g);
	mlx_string_put(w->mlx, w->ptr, 500, 290, HEXG, "G = ");
	mlx_string_put(w->mlx, w->ptr, 610, 290, HEXG, c);
	free(c);
	c = ft_itoa(w->b);
	mlx_string_put(w->mlx, w->ptr, 500, 320, HEXB, "B = ");
	mlx_string_put(w->mlx, w->ptr, 610, 320, HEXB, c);
	free(c);
	if (n == 20)
		return (n);
	else
		mlx_string_put(w->mlx, w->ptr, 455, n, HEXG + HEXB, "--");
	return (0);
}

int				set_options(t_win *w)
{
	int			p;
	int			i;
	int			z;

	w->h = 0;
	w->in = 0;
	w->nb_itr = ft_itoa(w->max_itr);
	mlx_clear_window(w->mlx, w->ptr);
	i = 0;
	mlx_string_put(w->mlx, w->ptr, 300, 100, HEXW, w->str_arr[i++]);
	z = 170;
	while (i < 8)
		mlx_string_put(w->mlx, w->ptr, 50, z += 30, HEXW, w->str_arr[i++]);
	mlx_string_put(w->mlx, w->ptr, 300, z, HEXG + HEXB, w->nb_itr);
	mlx_string_put(w->mlx, w->ptr, 500, 170, HEXW, w->str_arr[i++]);
	p = get_position(*w, 0);
	mlx_string_put(w->mlx, w->ptr, p, 180, HEXG, "--");
	if (w->col == get_color)
		if ((p = colors_in_menu(w, i)))
			mlx_string_put(w->mlx, w->ptr, p, z, HEXG + HEXB, "--");
	free(w->nb_itr);
	return (0);
}

void			colors_in_fract(t_win *w)
{
	if (w->c == 1)
	{
		w->nb_itr = ft_itoa(w->r);
		mlx_string_put(w->mlx, w->ptr, 275, 10, HEXR, "R = ");
		mlx_string_put(w->mlx, w->ptr, 315, 10, HEXR, w->nb_itr);
	}
	else if (w->c == 2)
	{
		w->nb_itr = ft_itoa(w->g);
		mlx_string_put(w->mlx, w->ptr, 275, 10, HEXG, "G = ");
		mlx_string_put(w->mlx, w->ptr, 315, 10, HEXG, w->nb_itr);
	}
	else if (w->c == 3)
	{
		w->nb_itr = ft_itoa(w->b);
		mlx_string_put(w->mlx, w->ptr, 275, 10, HEXB, "B = ");
		mlx_string_put(w->mlx, w->ptr, 315, 10, HEXB, w->nb_itr);
	}
}

int				print_help(t_win *w)
{
	w->z_count = ft_itoa(w->z);
	mlx_string_put(w->mlx, w->ptr, 50, 10, HEXW, "zoom (scroll):");
	mlx_string_put(w->mlx, w->ptr, 210, 10, HEXW, w->z_count);
	if (!w->c || w->col != get_color)
	{
		w->nb_itr = ft_itoa(w->max_itr);
		mlx_string_put(w->mlx, w->ptr, 275, 10, HEXW, w->str_arr[7]);
		mlx_string_put(w->mlx, w->ptr, 525, 10, HEXW, w->nb_itr);
	}
	else
		colors_in_fract(w);
	if (w->f == print_julia)
		mlx_string_put(w->mlx, w->ptr, 50, 35, HEXW, w->str_arr[11]);
	mlx_string_put(w->mlx, w->ptr, 50, 55, HEXW, w->str_arr[12]);
	mlx_string_put(w->mlx, w->ptr, 50, 75, HEXW, w->str_arr[13]);
	mlx_string_put(w->mlx, w->ptr, 50, 95, HEXW, w->str_arr[14]);
	free(w->nb_itr);
	free(w->z_count);
	return (0);
}
