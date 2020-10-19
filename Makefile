NAME=		cub3d.out
SRCS=		main.c \
			check_file.c \
			file_utils.c \
			init_struct.c \
			parse_file.c \
			set_map.c \
			set_settings.c
OBJS=		${addprefix srcs/,${SRCS:.c=.o}}
HEAD=		-I includes -I libft/includes
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra
LIB_FILE=	libft/libft.a

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
