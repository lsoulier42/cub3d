NAME=		Cub3D
SRCS=		main.c \
			parse_file.c \
			set_map.c \
			set_settings.c \
			set_struct.c \
			exit_game.c \
			error_utils.c \
			mlx_utils.c \
			render_minimap.c \
			collisions.c \
			init_game.c \
			draw_rect.c \
			draw_line.c \
			draw_line_utils.c \
			draw_line_angle_utils.c \
			draw_circle.c \
			geometry_utils.c \
			event_mngt.c \
			raycasting.c \
			raycasting_intercept.c \
			render_wall.c \
			render_background.c \
			texture.c \
			init_game_utils.c \
			check_config.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIBFT_DIR=	libft
MLX_DIR=	minilibx
LDFLAGS=	-L ${LIBFT_DIR} -L ${MLX_DIR}
LIBS=		-lm -lft -lmlx -lXext -lX11

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} ${LIBS}
all:	${NAME}
clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME}
re:	fclean all
.PHONY:	all clean fclean re
