SRCS	= ./srcs/cub*.c

OBJS	= ./srcs/cub*.o

NAME	= cub3d

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${SRCS} ./srcs/cub3d.h
		@make -C ./srcs/
		@mv ./srcs/cub3d .

clean:
		${RM} ${OBJS}
		${RM} ./libft/*.o
		${RM} ./gnl/*.o
		${RM} ./srcs/*.o
		${RM} ./srcs/gnl.a
		${RM} ./srcs/libft.a

fclean:	clean
		${RM} ${NAME}
		${RM} libft.a
		${RM} gnl.a

re:		fclean all

.PHONY:		re all clean fclean