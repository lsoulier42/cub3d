NAME=		cub3d.out
SRCS=		main.c \
			file_utils.c \
			parse_file.c \
			set_map.c \
			set_settings.c \
			set_struct.c \
			test_fct.c \
			pixel.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes -I minilibx
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIB_FILE=	-lft -L libft -lmlx -L minilibx -framework OpenGL -framework AppKit

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${LIB_FILE} ${OBJS} -o ${NAME}
all:	${NAME}
clean:
		rm -rf ${OBJS}
fclean:	clean
		rm -rf ${NAME}
re:	fclean all
.PHONY:	all clean fclean re
