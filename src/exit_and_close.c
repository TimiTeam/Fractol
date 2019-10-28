/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:19:38 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 20:20:00 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_map(char **str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int			exit_x(t_win *w)
{
	ft_strdel(&w->title);
	free_map(w->str_arr);
	mlx_destroy_window(w->mlx, w->ptr);
	exit(0);
	return (0);
}

void		error_message(int code, t_win *w)
{
	ft_putendl(strerror(code));
	if (code == 22)
	{
		ft_putstr("Hi, you can choose a ");
		ft_putendl("few different fractals.");
		ft_putstr("All you need is enter the name");
		ft_putendl(" of the one fractal below:");
		ft_putendl("1) Julia");
		ft_putendl("2) Mandelbrot");
		ft_putendl("3) Burning Ship");
		ft_putendl("4) Autor");
		exit(1);
	}
	exit_x(w);
}
