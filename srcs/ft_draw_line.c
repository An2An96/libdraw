/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:21:21 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/23 18:11:17 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	ft_draw_line_one_pix(t_mlx *visualiser, t_params *data, int color)
{
	double	length;
	double	side[3];
	double	sin_a;
	double	cos_a;

	side[1] = data->y2 - data->y;
	side[2] = data->x2 - data->x;
	side[0] = sqrt(pow(side[1], 2) + pow(side[2], 2));
	sin_a = side[1] / side[0];
	cos_a = side[2] / side[0];
	length = side[0];
	while ((int)length > 0)
	{
		mlx_pixel_put(
			visualiser->mlx_ptr, visualiser->win_ptr,
			round(data->x + length * cos_a),
			round(data->y + length * sin_a),
			color);
		length--;
	}
}

void		ft_draw_line(t_mlx *visualiser, t_params *data, int color)
{
	t_params	tmp;
	double		offset;
	double		side[3];
	double		sin_b;
	double		cos_b;

	side[1] = data->y2 - data->y;
	side[2] = data->x2 - data->x;
	side[0] = sqrt(pow(side[1], 2) + pow(side[2], 2));
	sin_b = side[2] / side[0];
	cos_b = side[1] / side[0];
	offset = -(data->line_width / 2);
	while (offset < data->line_width / 2.0)
	{
		tmp.x = data->x + (offset) * cos_b;
		tmp.y = data->y + (-offset) * sin_b;
		tmp.x2 = data->x2 + offset * cos_b;
		tmp.y2 = data->y2 + (-offset) * sin_b;
		ft_draw_line_one_pix(visualiser, &tmp, color);
		offset++;
	}
}
