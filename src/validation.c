/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:20:54 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 21:21:04 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				check_fract(char *ar, t_win *w)
{
	w->h = 1;
	if (!ft_strcmp(ar, "Julia"))
	{
		guess_buttom(JULIA, w);
		return (1);
	}
	if (!ft_strcmp(ar, "Mandelbrot"))
	{
		guess_buttom(MANDELBROT, w);
		return (1);
	}
	if (!ft_strcmp(ar, "Burning Ship"))
	{
		guess_buttom(BURNING_SHIP, w);
		return (1);
	}
	if (!ft_strcmp(ar, "Autor"))
	{
		guess_buttom(TIMUR, w);
		return (1);
	}
	return (0);
}
