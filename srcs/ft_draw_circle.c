/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:33:17 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/23 15:16:50 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_circle(t_mlx *visualiser, t_params *data, int color)
{
	int		x;
	int		y;
	double	val;
	double	angle;

	val = PI / 180;
	angle = 0;
	while (angle < 360)
	{
		mlx_pixel_put(
			visualiser->mlx_ptr,
			visualiser->win_ptr,
			data->x + round(data->radius * cos(angle * val)),
			data->y + round(data->radius * sin(angle * val)),
			color);
		angle++;
	}
	return ;
}
