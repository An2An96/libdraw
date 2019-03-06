/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:33:17 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/26 19:27:23 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_circle(t_mlx *visualiser, t_params *data, int color)
{
	double	val;
	double	angle;
	int		pos[2];

	val = PI / 180;
	angle = 0;
	while (angle < 360)
	{
		pos[0] = data->x + round(data->radius * cos(angle * val));
		pos[1] = data->y + round(data->radius * sin(angle * val));
		if (data->img)
			data->img->data[pos[1] * (data->img->size_l / 4) + pos[0]] = color;
		else
			mlx_pixel_put(visualiser->mlx_ptr, visualiser->win_ptr,
				pos[0], pos[1], color);
		angle++;
	}
	return ;
}
