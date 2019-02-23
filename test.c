#include "draw.h"

int ft_close(void)
{
	exit(0);
	return (0);
}

int main()
{
	t_mlx *visualiser = ft_create_window(500, 500, "test");
	mlx_hook(visualiser->win_ptr, 17, 1L << 17, ft_close, NULL);
	t_params data;
	data.x2 = 50;
	data.y2 = 50;
	data.x = 250;
	data.y = 250;
	data.line_width = 40;
	ft_draw_line(visualiser, &data, 0x00FF00);
	data.x2 = 450;
	data.y2 = 50;
	data.x = 250;
	data.y = 250;
	data.line_width = 23;
	ft_draw_line(visualiser, &data, 0xFF0000);
	data.x2 = 250;
	data.y2 = 250;
	data.x = 50;
	data.y = 450;
	data.line_width = 11;
	ft_draw_line(visualiser, &data, 0x0000FF);
	data.x2 = 450;
	data.y2 = 450;
	data.x = 250;
	data.y = 250;
	data.line_width = 2;
	ft_draw_line(visualiser, &data, 0xFF00FF);
	data.radius = 100;
	ft_draw_circle(visualiser, &data, 0xFFFFFF);
	mlx_pixel_put(visualiser->mlx_ptr, visualiser->win_ptr, 250, 250, 0xFFFFFF);
	mlx_loop(visualiser->mlx_ptr);
	return (0);
}
