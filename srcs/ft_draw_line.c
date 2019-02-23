/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <wballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:21:21 by wballaba          #+#    #+#             */
/*   Updated: 2019/02/23 15:11:50 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_line(t_mlx *visualiser, t_params *data, int color, int x2, int y2)
{
	double	length;
	double	a;
	double	b;
	double	c;
	int		x;
	int		y;
	int		i;

	b = x2 - data->x;
	a = y2 - data->y;

	length = sqrt(pow(a, 2) + pow(b, 2));

	i = 1;
	c = length;
	while((int)length > 0)
	{
		x = data->x + length * (b /c);
		y = data->y + length * (a / c);
		mlx_pixel_put(visualiser->mlx_ptr, visualiser->win_ptr, x, y, color);
		length--;
	}
}
