/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bg_gradient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:38:33 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/26 18:50:47 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(
	t_params current, t_params start, t_params end, t_params delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light(
		(start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light(
		(start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_draw_bg_gradient(
	t_mlx *visualiser, t_params *data, int start_color, int end_color)
{
	t_params current;
	t_params start;
	t_params end;
	t_params delta;

	start.x = 0;
	start.y = 0;
	start.color = start_color;
	end.x = data->width;
	end.y = data->height;
	end.color = end_color;
	current.color = start.color;
	current.y = -1;
	while (++current.y < data->height)
	{
		current.x = -1;
		while (++current.x < data->width)
		{
			delta.x = current.x - start.x;
			delta.y = current.y - start.y;
			current.color = get_color(current, start, end, delta);

			if (data->img)
				data->img->data[current.y * data->width + current.x] =
					current.color;
			else
				mlx_pixel_put(visualiser->mlx_ptr, visualiser->win_ptr,
					current.x, current.y, current.color);
		}
	}
}
