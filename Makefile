# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/10/18 09:25:00 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 		= main.c
DIFF		= diffusion.c diffusion_hook.c cfiles/atoia.c cfiles/f_file_size.c cfiles/f_read.c cfiles/f_readlines.c
OBJS 		= ${SRCS:.c=.o}
DOBJS 		= ${DIFF:.c=.o}
LIBS 		= libalbaud/libs/mlx/_mlx/libmlx.a libalbaud/libalbaud.a
# LIBSS		= -Lminilibx_macos
NAME 		= digit
DNAME 		= diffusion
CC			= gcc
FRAMEWORK	= -framework OpenGL -framework AppKit
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

.c.o 	:
		${CC} ${CFLAGS} -I minilibx_macos -c $< -o ${<:.c=.o}
		
all 	: ${OBJS} ${LIBS}
		make -C libalbaud 
		${CC} ${CFLAGS} -o ${NAME} ${FRAMEWORK} ${OBJS} ${LIBS} ${LIBSS}

$(DNAME): ${DOBJS} ${LIBS}
		${CC} ${CFLAGS} -o ${DNAME} ${FRAMEWORK} ${DOBJS} ${LIBS} ${LIBSS}

${LIBS} :
		make -C libalbaud 

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME} 

re		: fclean all

c 		:
		find *.c cfiles/*.c | tr '\n' ' '

make	:
		make -C koflibc && make -C libia && make -C libia/mlib && make -C libia/mlib/vlib && make -C p && make

makere	:
		make re -C koflibc && make re -C libia && make re -C libia/mlib && make re -C libia/mlib/vlib && make re -C p && make re

run		: 
		make -C koflibc && make -C libia && make -C p && make && ./digit

test	: make
		${CC} ${CFLAGS} -o t ${FRAMEWORK} test.c ${LIBS} ${LIBSS}
		./t