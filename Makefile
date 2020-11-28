NAME=		cub3D
SRCS=		main.c \
			parsing.c \
			cub_file.c \
			parse_settings.c \
			parse_settings_utils.c \
			parsing_utils.c \
			parse_resolution.c \
			parse_textures.c \
			parse_colors.c \
			parse_map.c \
			parse_player.c \
			check_map.c \
			struct_utils.c \
			exit_game.c \
			error_utils.c \
			mlx_utils.c \
			mlx_utils2.c \
			collisions.c \
			init_game.c \
			geometry_utils.c \
			event_mngt.c \
			raycasting.c \
			raycasting_intercept.c \
			render_wall.c \
			render_background.c \
			textures.c \
			save_bmp.c \
			sprites.c \
			sprites_utils.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIBFT_DIR=	libft
MLX_DIR=	minilibx
LDFLAGS=	-L ${LIBFT_DIR} -L ${MLX_DIR}
LIBS=		-lm -lft -lmlx -lXext -lX11
DEFINE_DEFAULT= -D PROJECT_NAME="${NAME}"

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
$(NAME):	${OBJS}
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		${CC} ${CFLAGS} ${LDFLAGS} ${DEFINE_DEFAULT} ${OBJS} -o ${NAME} ${LIBS}
all:	${NAME}

clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME}
re:	fclean all
.PHONY:	all clean fclean re
