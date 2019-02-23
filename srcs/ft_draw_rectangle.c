/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:53:31 by rschuppe          #+#    #+#             */
/*   Updated: 2019/02/23 19:56:36 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

// static void	ft_draw_rectangle_helper(
// 	t_mlx *visualiser, t_params *data, int color)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < data->width)
// 	{
// 		j = 0;
// 		while (j < data->line_width)
// 		{
// 			mlx_pixel_put(
// 				visualiser->mlx_ptr, visualiser->win_ptr,
// 				data->x + i, data->y + j, color);
// 			mlx_pixel_put(
// 				visualiser->mlx_ptr, visualiser->win_ptr,
// 				data->x + i, data->y + data->height - j - 1, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_draw_rectangle(t_mlx *visualiser, t_params *data, int color)
{
	int i;
	int j;

	// t_params tmp;

	// tmp.line_width = data->line_width;

	// tmp.x = data->x;
	// tmp.y = data->y;
	// tmp.x2 = data->x2;
	// tmp.y2 = data->y;
	// ft_draw_line(visualiser, &tmp, color);

	// tmp.x = data->x2;
	// tmp.y = data->y;
	// tmp.x2 = data->x2;
	// tmp.y2 = data->y2;
	// ft_draw_line(visualiser, &tmp, color);

	// tmp.x = data->x2;
	// tmp.y = data->y2;
	// tmp.x2 = data->x;
	// tmp.y2 = data->y2;
	// ft_draw_line(visualiser, &tmp, color);

	// tmp.x = data->x;
	// tmp.y = data->y2;
	// tmp.x2 = data->x;
	// tmp.y2 = data->y;
	// ft_draw_line(visualiser, &tmp, color);

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->line_width)
		{
			mlx_pixel_put(
				visualiser->mlx_ptr, visualiser->win_ptr,
				data->x + i, data->y + j, color);
			mlx_pixel_put(
				visualiser->mlx_ptr, visualiser->win_ptr,
				data->x + i, data->y + data->height - j - 1, color);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->line_width)
		{
			mlx_pixel_put(
				visualiser->mlx_ptr, visualiser->win_ptr,
				data->x + j, data->y + i, color);
			mlx_pixel_put(
				visualiser->mlx_ptr, visualiser->win_ptr,
				data->x + data->width - j - 1, data->y + i, color);
			j++;
		}
		i++;
	}
}
