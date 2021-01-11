# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 15:06:50 by alafranc          #+#    #+#              #
#    Updated: 2021/01/11 14:52:59 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# DONT FORGET TO UNCOMMENT CLEAN AND FCLEAN MINILIBX
NAME			= cub3d
FILES			= ft_utility.c ft_parsing.c  map_is_valid.c printer.c \
main.c


CC				= clang
OBJS 			= ${FILES:.c=.o}
FLAGS			= -Wall -Wextra -Werror

NAME_LIBFT 		= libft.a
LIBFT_PATH 		= libft/
LIBFT			= $(addprefix ${LIBFT_PATH}, ${NAME_LIBFT})
NAME_MINILIBX	= libmlx.dylib
MINILIBX_PATH 	= minilibx/
MINILIBX		= $(addprefix ${MINILIBX_PATH}, ${NAME_MINILIBX})

all: 			${NAME}	

lib: 
				make -C ${LIBFT_PATH}
				make -C ${MINILIBX_PATH}
				cp ${LIBFT} .
				cp ${MINILIBX} .

%.o : %.c 		cub3d.h
				${CC} ${FLAGS} -c $< -o $@

${NAME}: 		lib ${OBJS}
		${CC} ${OBJS} -o ${NAME} ${NAME_LIBFT} ${NAME_MINILIBX}

clean:
			make -C ${LIBFT_PATH} clean
			#make -C ${MINILIBX_PATH} clean
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}
			#${RM} ${MINILIBX}

re:			fclean all


.PHONY: all clean fclean re bonus lib test
