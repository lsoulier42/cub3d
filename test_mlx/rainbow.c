color = create_trgb(0, parsed_map->floor_color.r, parsed_map->floor_color.g, parsed_map->floor_color.b);
		img.img = mlx_new_image(mlx_ptr, 800, 600);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		print_rainbow(&img);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);


void print_line(t_image_data *img, int color, int x_start, int y_start)
{
	int i = -1;
	int j;

	while (++i < 50)
	{
		j = -1;
		while (++j < 10)
			my_mlx_pixel_put(img, x_start + i, y_start + j, color);
	}
}

void print_rainbow(t_image_data *img)
{
	/*int red = create_trgb(0, 255, 0, 0);
	int blue = create_trgb(0, 0, 0, 255);
	int green = create_trgb(0, 0, 255, 0);
	int purple = create_trgb(0, 128, 0, 128);
	int orange = create_trgb(0, 255, 168, 0);
	int yellow = create_trgb(0, 255, 255, 0);
	int skyblue = create_trgb(0, 135, 206, 235);
	int rainbow[7] = {red, orange, yellow, green, skyblue, blue, purple};*/
	int i = -1;

	while (++i < 255)
		print_line(img, create_trgb(0, i, 0, 0), 50, 50 + i);
}

void draw_square(t_image_data *img, int x, int y, int size)
{
	int i;
	int j;
	int color;

	i = -1;
	color = create_trgb(0, 255, 255, 255);
	while (++i < size)
	{
		j = -1;
		my_mlx_pixel_put(img, x + i, y, color);
		while (++j < size)
			my_mlx_pixel_put(img, x + i, y + j, color);
	}
}

void erase_line(t_image_data *img, int x, int y, int size)
{
	int i;

	i = -1;
	while (++i < size)
		my_mlx_pixel_put(img, x, y + i, create_trgb(0, 0, 0, 0));
}

int render_next_frame(t_mlx_vars *vars)
{
	static int x = 0;
	draw_square(&vars->img, ++x, 50, 50);
	erase_line(&vars->img, x, 50, 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}

mlx_string_put(vars.mlx, vars.win, img_width + 10, img_height + 10, create_trgb(0, 255, 0, 0), "test");
