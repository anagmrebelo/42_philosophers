SRCS		= 	src/utils/ft_atoi.c\
				src/utils/ft_bzero.c\
				src/utils/ft_calloc.c\
				src/creation.c\
				src/routine.c\
				src/status.c\
				src/time.c\
				src/write.c\
				src/init.c\
				src/game_status.c\
				src/philosophers.c
			
SRCS_BONUS	= 	src_bonus/gnl/get_next_line_bonus.c\

OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= philo
NAME2		= .filetrack
HEADER		= includes/philosophers.h

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			@${RM} ${OBJS_BONUS}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

bonus:		${NAME2} 

${NAME2}:	${OBJS_BONUS} ${HEADER}
			@${RM} ${OBJS}
			${CC} ${CFLAGS} ${SRCS_BONUS} -o ${NAME}
			@touch $@

clean:		
		@${RM} ${OBJS}
		@${RM} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}
		@${RM} ${NAME2}

re:		fclean all

.PHONY:		all clean fclean re bonus
