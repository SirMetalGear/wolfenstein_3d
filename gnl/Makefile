SRCS	= $(shell find . -name "get_*.c")

OBJS	= ${SRCS:.c=.o}

NAME	= gnl.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o} -D BUFFER_SIZE=1

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

bonus:	all

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		re all clean fclean bonus
