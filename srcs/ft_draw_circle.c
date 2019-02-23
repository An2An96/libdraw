/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:33:17 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/23 14:13:51 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_circle(t_mlx *visualiser, t_params *data, int color)
{
	double angle;
	double x;
	double y;

	angle = 0;
	while (angle < 360)
	{
		printf("%f\n", angle);
		x = data->x + data->radius * sin(angle);
		y = data->y + data->radius * cos(angle);
		printf("% ")
		mlx_pixel_put(visualiser->mlx_ptr, visualiser->win_ptr, data->x, data->y, color);
		angle++;
	}
	return ;
}
