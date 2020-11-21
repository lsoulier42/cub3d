//
// Created by Louise on 09/11/2020.
//

/*void	init_player_sprites(t_mlx_vars *vars)
{
	t_dimension up;
	t_dimension down;
	t_dimension west;
	t_dimension est;

	vars->player_up.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_up.xpm", &up.width, &up.height);
	vars->player_down.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_down.xpm", &down.width, &down.height);
	vars->player_west.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_west.xpm", &west.width, &west.height);
	vars->player_est.img = mlx_xpm_file_to_image(vars->mlx, "./img/player_est.xpm", &est.width, &est.height);
	change_player_img(vars);
}*/

/*void change_player_img(t_mlx_vars *vars)
{
	if (vars->current_card == 'N')
		vars->player_img = vars->player_up;
	else if (vars->current_card == 'S')
		vars->player_img = vars->player_down;
	else if (vars->current_card == 'W')
		vars->player_img = vars->player_west;
	else if (vars->current_card == 'E')
		vars->player_img = vars->player_est;
}*/


/*
char change_card(int keycode)
{
	char new_card;

	new_card = 0;
	if (keycode == ARROW_UP)
		new_card = 'N';
	else if (keycode == ARROW_DOWN)
		new_card = 'S';
	else if (keycode == ARROW_LEFT)
		new_card = 'W';
	else if (keycode == ARROW_RIGHT)
		new_card = 'E';
	return (new_card);
}

int player_move(int keycode, t_mlx_vars *vars)
{
	int		collision;
	t_point	previous_pos;
	char	previous_card;

	collision = 0;
	previous_pos = vars->current_pos;
	previous_card = vars->current_card;
	vars->current_card = change_card(keycode);
	if (keycode == ARROW_UP && vars->map[vars->current_pos.y - 1][vars->current_pos.x] == '0')
		vars->current_pos.y--;
	else if (keycode == ARROW_DOWN && vars->map[vars->current_pos.y + 1][vars->current_pos.x] == '0')
		vars->current_pos.y++;
	else if (keycode == ARROW_LEFT && vars->map[vars->current_pos.y][vars->current_pos.x - 1] == '0')
		vars->current_pos.x--;
	else if (keycode == ARROW_RIGHT && vars->map[vars->current_pos.y][vars->current_pos.x + 1] == '0')
		vars->current_pos.x++;
	else
		collision = 1;
	if (!collision) {
		erase_previous_pos(vars, previous_pos);
	}
		print_player(vars, vars->current_pos);
		if (previous_card != vars->current_card)
			erase_previous_ray(vars, previous_pos, previous_card);
		vars->wall_touched = print_ray(vars, vars->current_pos);
	return (1);
}

void	print_player(t_mlx_vars *vars, t_point player_pos)
{
	void *img;
	int x;
	int y;

	img = vars->player_img.img;
	x = player_pos.x * vars->tile_size;
	y = player_pos.y * vars->tile_size;
	erase_previous_pos(vars, player_pos);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void erase_previous_pos(t_mlx_vars *vars, t_point player_pos)
{
	t_image_data empty;
	int x;
	int y;

	x = player_pos.x * vars->tile_size;
	y = player_pos.y * vars->tile_size;
	my_mlx_new_image(vars->mlx, &empty, vars->tile_size, vars->tile_size);
	draw_square(&empty, color_trgb(WHITE), vars->tile_size);
	mlx_put_image_to_window(vars->mlx, vars->win, empty.img, x, y);
}*/

void	draw_square(t_image_data *img, int color, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		my_mlx_pixel_put(img, i, 0, color);
		while (++j < size)
			my_mlx_pixel_put(img, i, j, color);
	}
}

/*void	set_map_elem(t_mlx_vars *vars, t_image_data elem[ELEM_TOTAL])
{
	int size;

	size = vars->tile_size;
	my_mlx_new_image(vars->mlx, &elem[EMPTY], size, size);
	my_mlx_new_image(vars->mlx, &elem[WALL], size, size);
	my_mlx_new_image(vars->mlx, &elem[SPRITE], size, size);
	draw_square(&elem[EMPTY], color_trgb(WHITE), size);
	draw_square(&elem[WALL], color_trgb(BLUE), size);
	draw_square(&elem[SPRITE], color_trgb(YELLOW), size);
}*/

/*void	print_map(t_mlx_vars *vars, char **map)
{
	t_image_data	elem[ELEM_TOTAL];
	int 			i;
	int 			j;
	int 			x;
	int 			y;

	i = -1;
	set_map_elem(vars, elem);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] >= '0' && map[i][j] < '0' + ELEM_TOTAL)
			{
				x = j * vars->tile_size;
				y = i * vars->tile_size;
				mlx_put_image_to_window(vars->mlx, vars->win,
					elem[map[i][j] - '0'].img, x, y);
			}
	}
}*/

void erase_previous_frame(t_mlx_vars *vars, t_point previous_pos)
{
	t_image_data empty;
	t_player player;

	player = vars->player;
	my_mlx_new_image(vars, &empty, player.size + 1, player.size + 1);
	draw_square(&empty, color_trgb(WHITE), player.size + 1);
	mlx_put_image_to_window(vars->mlx, vars->win, empty.img, previous_pos.x - player.size / 2, previous_pos.y - player.size / 2);
}

/*t_image_data create_vertical_ray(t_mlx_vars *vars)
{
	t_image_data vertical_line;
	int i;

	i = -1;
	my_mlx_new_image(vars->mlx, &vertical_line, 1, vars->tile_size);
	while (++i < vars->tile_size)
		my_mlx_pixel_put(&vertical_line, 0, i, color_trgb(RED));
	return (vertical_line);
}

t_image_data create_horizontal_ray(t_mlx_vars *vars)
{
	t_image_data horizontal_line;
	int j;

	j = -1;
	my_mlx_new_image(vars->mlx, &horizontal_line, vars->tile_size, 1);
	while (++j < vars->tile_size)
		my_mlx_pixel_put(&horizontal_line, j, 0, color_trgb(RED));
	return (horizontal_line);
}

t_point print_ray(t_mlx_vars *vars, t_point current_pos)
{
	t_image_data	line;
	t_point			wall_touched;
	int				i;

	i = 0;
	set_point(&wall_touched, -1, -1);
	if (vars->current_card == 'N' || vars->current_card == 'S')
		line = create_vertical_ray(vars);
	else
		line = create_horizontal_ray(vars);
	if (vars->current_card == 'N')
		while (vars->map[vars->current_pos.y - ++i][vars->current_pos.x] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * vars->tile_size) + vars->tile_size / 2, (current_pos.y - i) * vars->tile_size);
	else if (vars->current_card == 'S')
		while (vars->map[vars->current_pos.y - --i][vars->current_pos.x] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x * vars->tile_size) + vars->tile_size / 2, (current_pos.y - i) * vars->tile_size);
	else if (vars->current_card == 'W')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - ++i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * vars->tile_size, (current_pos.y * vars->tile_size) + vars->tile_size / 2);
	else if (vars->current_card == 'E')
		while (vars->map[vars->current_pos.y][vars->current_pos.x - --i] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, line.img, (current_pos.x - i) * vars->tile_size, (current_pos.y * vars->tile_size) + vars->tile_size / 2);
	if (vars->current_card == 'N' || vars->current_card == 'S')
		set_point(&wall_touched, current_pos.x, current_pos.y - i);
	else
		set_point(&wall_touched, current_pos.x - i, current_pos.y);
	return (wall_touched);
}

void	erase_previous_ray(t_mlx_vars *vars, t_point previous_pos, char previous_card)
{
	int				i;
	t_image_data	empty;

	i = 0;
	my_mlx_new_image(vars->mlx, &empty, vars->tile_size, vars->tile_size);
	draw_square(&empty, color_trgb(WHITE), vars->tile_size);
	if (previous_card == 'N')
		while (++i < previous_pos.y - vars->wall_touched.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, vars->wall_touched.x * vars->tile_size, (vars->wall_touched.y + i) * vars->tile_size);
	else if (previous_card == 'S')
		while (++i < vars->wall_touched.y - previous_pos.y)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, previous_pos.x * vars->tile_size, (previous_pos.y + i) * vars->tile_size);
	else if (previous_card == 'W')
		while (++i < previous_pos.x - vars->wall_touched.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (vars->wall_touched.x + i) * vars->tile_size, vars->wall_touched.y * vars->tile_size);
	else if (previous_card == 'E')
		while (++i < vars->wall_touched.x - previous_pos.x)
			mlx_put_image_to_window(vars->mlx, vars->win, empty.img, (previous_pos.x + i) * vars->tile_size, previous_pos.y * vars->tile_size);
}*/

typedef struct 	s_file
{
	char	*fullname;
	char	*ext;
	char	*filename;
	char 	*path;
	int		fd;
}				t_file;

int		open_game_file(t_file *file, char *fullname)
{
	int 	fd;

	init_file(file);
	fd = open(fullname, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!(set_file(file, fullname, fd)))
		return (0);
	return (1);
}

void 	init_file(t_file *file)
{
	file->fullname = NULL;
	file->ext = NULL;
	file->filename = NULL;
	file->path = NULL;
	file->fd = 0;
}

int		set_file(t_file *file, char *fullname, int fd)
{
	size_t	len;
	size_t	point;
	size_t	slash;

	point = 0;
	slash = 0;
	if (fullname)
	{
		len = ft_strlen(fullname);
		file->fullname = fullname;
		while (fullname[point] && fullname[len - point - 1] != '.')
			point++;
		while (fullname[slash] && fullname[len - slash - 1] != '/')
			slash++;
		if (!(file->filename = (char *)malloc(sizeof(char) * (slash - point))) ||
			!(file->ext = (char *)malloc(sizeof(char) * (point + 1))) ||
			!(file->path = (char *)malloc(sizeof(char) * (len - slash + 1))))
			return (0);
		ft_strlcpy(file->filename, fullname + len - slash, slash - point);
		ft_strlcpy(file->path, fullname, len - slash + 1);
		ft_strlcpy(file->ext, fullname + len - point, point + 1);
	}
	file->fd = fd;
	return (1);
}

int 	destroy_file(t_file file)
{
	if(ft_strncmp("cub", file.ext, 3) != 0)
		free(file.fullname);
	free(file.ext);
	free(file.filename);
	free(file.path);
	close(file.fd);
	return (0);
}

void test_opened_file(t_file file)
{
	printf("---------Test de lecture du fichier .cub---------\n");
	printf("Fullname: %s\n", file.fullname);
	printf("Filename: %s\n", file.filename);
	printf("Extension: %s\n", file.ext);
	printf("Path: %s\n", file.path);
	printf("File descriptor: %d\n", file.fd);
}

fd = check_file(argv[1]);
if (fd == -1)
{
error_occured = error_msg(FILE_ERROR);
return (0);
}

void 	complete_map(t_game *parsed_map)
{
	int line_len;
	int x;
	int y;
	char **map;
	char *new_line;

	y = -1;
	map = parsed_map->map;
	while (map[++y])
	{
		line_len = (int)ft_strlen(map[y]);
		x = -1;
		if (line_len < parsed_map->map_res.width)
		{
			new_line = malloc(sizeof(char) * (parsed_map->map_res.width + 1));
			if (new_line)
			{
				ft_strlcpy(new_line, map[y], line_len + 1);
				free(map[y]);
				map[y] = new_line;
				while (++x < parsed_map->map_res.width - line_len)
					map[y][line_len + x] = ' ';
				map[y][parsed_map->map_res.width] = '\0';
			}
		}
	}
}

void	get_sprite(t_image_data sprite_sheet,
				   t_image_data *sprite, t_point sprite_location, int size)
{
	int		x;
	int		y;
	char	*dst;
	char	*src;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			src = sprite_sheet.addr
				  + (((int)sprite_location.y + y) * sprite_sheet.line_length
					 + ((int)sprite_location.x + x)
					   * (sprite_sheet.bits_per_pixel / 8));
			dst = sprite->addr
				  + (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
			*(unsigned int*)dst = *(unsigned int*)src;
		}
	}
}

int wall_line;
double height_ratio;
int color;
int y;

y = -1;
if (vars->rays[ray_index].was_hit_north)
{
wall_line = fmod(vars->rays[ray_index].wall_hit.x, vars->south_text->width);
height_ratio = elem_dimension.height / vars->south_text->height;
while (++y < elem_dimension.height)
{
color = get_texture_color(vars->south_text, wall_line, y / height_ratio);
my_mlx_pixel_put(vars->view, location.x, location.y + y, color);
}
}


t_bmp_color	*fill_color_buffer(t_image_data *first_frame, t_dimension img_res)
{
	t_bmp_color *color_buffer;
	t_bmp_color	bmp_color;
	int			x;
	int 		y;

	x = -1;
	color_buffer = (t_bmp_color*)malloc(img_res.width
										* img_res.height * sizeof(t_bmp_color));
	if (!color_buffer)
		return (NULL);
	while (++x < img_res.width)
	{
		y = -1;
		while (++y < img_res.height)
		{
			bmp_color = convert_trgb_to_bmp(first_frame, x, y);
			color_buffer[((int)img_res.width * y) + x] = bmp_color;
		}
	}
	return (color_buffer);
}