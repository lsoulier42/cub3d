NAME=		cub3d.out
SRCS=		main.c \
			file_utils.c \
			parse_file.c \
			set_map.c \
			set_settings.c \
			set_struct.c \
			mlx_utils.c \
			render_map.c \
			render_player.c \
			init_vars.c \
			draw_rect.c \
			draw_line.c \
			draw_line_utils.c \
			draw_line_angle_utils.c \
			draw_circle.c \
			distance_utils.c \
			angle_utils.c \
			event_mngt.c \
			raycasting.c \
			raycasting_intersection.c \
			render_wall.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LDFLAGS=	-L libft -L minilibx
LIBS=		-lm -lft -lmlx -lXext -lX11

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME} ${LIBS}
all:	${NAME}
clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME}
re:	fclean all
.PHONY:	all clean fclean re
