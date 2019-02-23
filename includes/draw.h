/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:34:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/23 14:09:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_params
{
	int			x;
	int			y;
	int			radius;
}				t_params;

t_mlx	*ft_create_window(int width, int height, char *title);
void	ft_draw_circle(t_mlx *visualiser, t_params *data, int color);

#endif