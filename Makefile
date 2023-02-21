# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 23:58:15 by anarebelo         #+#    #+#              #
#    Updated: 2023/02/22 00:07:49 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME		= philo

# FILES
# **************************************************************************** #
SRCS		= 	utils/ft_atoi.c\
				utils/ft_bzero.c\
				utils/ft_calloc.c\
				creation.c\
				routine.c\
				status.c\
				time.c\
				write.c\
				init.c\
				game_status.c\
				philosophers.c
			
OBJS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
DEPS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I includes

# COMPILATION
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror 
RM					= rm -rf

# RULES
# **************************************************************************** #
all:		${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

${NAME}:	${OBJS} 
			${LINK} ${CFLAGS} $(INCLUDE) ${OBJS} ${LIB} -o ${NAME}

clean:		
		@${RM} ${OBJS_DIR}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

 -include ${DEPS}

.PHONY:		all clean fclean re
