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
	data.x = 50;
	data.y = 50;
	data.radius = 10;
	ft_draw_circle(visualiser, &data, 0xFFFFFF);
	mlx_loop(visualiser->mlx_ptr);
	return (0);
}