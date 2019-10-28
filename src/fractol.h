/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbujalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:26:20 by tbujalo           #+#    #+#             */
/*   Updated: 2019/03/03 21:45:42 by tbujalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include <pthread.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define THREADS 8
# define JULIA 38
# define MANDELBROT 46
# define TIMUR 17
# define BURNING_SHIP 11
# define ZOOM_SIZE 290
# define HEXR 0xF20000
# define HEXG 0x1CAB00
# define HEXB 0x3333FF
# define HEXW 0xFFFFFF

typedef struct	s_fract
{
	int			*d;
	int			y_s;
	int			y_e;
	int			size_x;
	int			size_y;
	double		cen_x;
	double		cen_y;
	int			max_itr;
	double		m_x;
	double		m_y;
	double		zoom_x;
	double		zoom_y;
	double		c_re;
	double		c_im;
	void		*col;
	int			r;
	int			g;
	int			b;
}				t_fract;

typedef struct	s_win
{
	void		*ptr;
	void		*mlx;
	char		*title;
	int			size_x;
	int			size_y;
	void		*img;
	int			bi;
	int			l;
	int			en;
	int			*d;
	void		*f;
	void		*col;
	int			r;
	int			g;
	int			b;
	char		*nb_itr;
	int			max_itr;
	double		m_x;
	double		m_y;
	double		c_re;
	double		c_im;
	double		zoom;
	int			step;
	char		*z_count;
	int			in;
	int			h;
	int			move;
	double		c_x;
	double		c_y;
	double		cp_r;
	double		cp_i;
	double		zoom_ar[ZOOM_SIZE + 1];
	int			z;
	long int	move_ar[ZOOM_SIZE + 1];
	int			c;
	char		**str_arr;
	double		zoom_x;
	double		zoom_y;
}				t_win;

int				exit_x(t_win *par);
t_fract			*make_fract(t_win *w, int from, int step);
int				run_thread(t_win *w);
int				get_color(t_fract fr, int itr);
void			*print_mandel(void *par);
void			*print_julia(void *par);
void			*print_ship(void *par);
void			*my_fract(void *p);
int				set_options(t_win *w);
int				print_help(t_win *w);
int				mouse_ivent(int key, int x, int y, t_win *w);
int				stop_move(int key, t_win *w);
int				mouse_move(int x, int y, t_win *w);
int				get_color(t_fract fr, int itr);
int				mix_colors(t_fract fr, int itr);
int				color_three(t_fract fr, int itr);
void			guess_color(int key, t_win *w);
int				get_position(t_win w, int m);
int				check_fract(char *ar, t_win *w);
int				guess_buttom(int key, t_win *w);
void			error_message(int code, t_win *w);
void			set_state(t_win *w);

#endif
