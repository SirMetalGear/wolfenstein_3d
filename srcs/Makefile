SRCS	= $(shell find . -name "cub*.c")

OBJS	= ${SRCS:.c=.o}

NAME	= cub3d

CC		= gcc

MAKELIB	= make -C ./../libft/

MAKEGNL = make -C ./../gnl/

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} cub3d.h
		${MAKELIB}
		cp ./../libft/libft.a .
		${MAKEGNL}
		cp ./../gnl/gnl.a . 
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L. -I. libft.a gnl.a libmlx.a -framework OpenGL -framework Appkit

clean:
		${RM} ${OBJS}
		${RM} ./../libft/*.o
		${RM} ./../gnl/*.o

fclean:	clean
		${RM} ${NAME}
		${RM} libft.a
		${RM} gnl.a

re:		fclean all

.PHONY:		re all clean fclean