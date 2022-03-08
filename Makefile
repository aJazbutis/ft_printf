# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 19:08:14 by ajazbuti          #+#    #+#              #
#    Updated: 2021/11/06 19:32:19 by ajazbuti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_inspect.c ft_convert.c ft_solve_hex.c ft_solve_s.c\
	  ft_solve_c.c ft_solve_di.c ft_solve_p.c ft_solve_field.c\
	  ft_prec_nbr.c ft_solve_u.c ft_put_field.c

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

SUB_DIR = libft/

SRC_DIR = sources/

INC_DIR = -I./includes -I./libft

SRC_O = ${SRC:.c=.o}

all: ${NAME}

bonus: re

libft:
	${MAKE} -C ${SUB_DIR}

%.o: ${SRC_DIR}%.c
	${CC} ${CFLAGS} ${INC_DIR} -c -o $@ $^

${NAME}: libft ${SRC_O}
	ar -r $@ ${SRC_O} ${SUB_DIR}*.o

clean:
	${RM} ${SRC_O}
	${RM} ${SUB_DIR}*.o

fclean: clean
	${RM} ${NAME}
	${RM} ${SUB_DIR}*.a

re: fclean all

.PHONY: all clean fclean re bonus libft
