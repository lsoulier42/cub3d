NAME=		cub3D
SRCS=		main.c \
			parsing.c \
			cub_file.c \
			parsing_utils.c \
			parsing_utils2.c \
			parsing_resolution.c \
			parsing_textures.c \
			parsing_colors.c \
			parsing_map.c \
			parsing_player.c \
			struct_utils.c \
			exit_game.c \
			error_utils.c \
			mlx_utils.c \
			collisions.c \
			init_game.c \
			geometry_utils.c \
			event_mngt.c \
			raycasting.c \
			raycasting_intercept.c \
			render_wall.c \
			render_background.c \
			texture.c \
			save_bmp.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=
LIBFT_DIR=	libft
MLX_DIR=	minilibx
LDFLAGS=	-L ${LIBFT_DIR} -L ${MLX_DIR}
LIBS=		-lm -lft -lmlx -lXext -lX11

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${CFLAGS} ${LDFLAGS} -D PROJECT_NAME="${NAME}" ${OBJS} -o ${NAME} ${LIBS}
		./cub3D map.cub;
all:	${NAME}
clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME}
re:	fclean all
.PHONY:	all clean fclean re
