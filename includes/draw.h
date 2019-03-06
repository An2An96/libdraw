/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:34:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/03/06 21:14:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define PI			3.14159265

# define KEY_SPACE	49
# define KEY_ESC	53

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_params
{
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			radius;
	int			width;
	int			height;
	int			line_width;
}				t_params;

typedef struct	s_side
{
	double		a;
	double		b;
	double		c;
}				t_side;


t_mlx	*ft_create_window(int width, int height, char *title);
void	ft_draw_circle(t_mlx *visualiser, t_params *data, int color);
void	ft_draw_rectangle(t_mlx *visualiser, t_params *data, int color);
void	ft_draw_line(t_mlx *visualiser, t_params *data, int color);

#endif
