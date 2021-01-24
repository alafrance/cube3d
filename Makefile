# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 15:06:50 by alafranc          #+#    #+#              #
#    Updated: 2021/01/24 17:04:21 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# DONT FORGET TO UNCOMMENT CLEAN AND FCLEAN MINILIBX
NAME			= cub3d
FILES			= ft_utility.c printer.c ft_error.c \
$(addprefix parsing/, ft_parsing.c ft_check_data.c ft_path_texture.c check_map.c) \
$(addprefix raycasting/, ft_raycasting.c ft_ray_calc.c ft_window.c ft_move_camera.c)
INC_FILES		= cub3d.h
INC_PATH		= ./includes/
INC				= $(addprefix ${INC_PATH}, ${INC_FILES})
SRC_PATH		= ./srcs/
SRC				= $(addprefix ${SRC_PATH}, ${FILES})

CC				= clang
OBJS 			= ${SRC:.c=.o}
FLAGS			= -Wall -Wextra -Werror

#LIBRARY
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

%.o: %.c 		${INC}
				${CC} ${FLAGS} -c $< -o $@ -I ${INC_PATH}

${NAME}: 		lib ${OBJS}
				${CC} ${OBJS} main.c -o ${NAME} ${NAME_LIBFT} ${NAME_MINILIBX} -I ${INC_PATH}

clean:
				make -C ${LIBFT_PATH} clean
				#make -C ${MINILIBX_PATH} clean
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}
				${RM} ${LIBFT}
				${RM} ${NAME_LIBFT}
				${RM} ${NAME_MINILIBX}
				#${RM} ${MINILIBX}

re:				fclean all


.PHONY: all clean fclean re bonus lib test
