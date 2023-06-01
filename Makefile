# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asekmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:21:09 by asekmani          #+#    #+#              #
#    Updated: 2022/12/01 12:18:11 by asekmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS= main.c \
	check_error.c \
	init.c utils.c \
	swap.c \
	rotate.c \
	rrotate.c \
	push.c \
	index_rank.c \
	sort_part_1.c \
	sort_part_2.c \
	sort_part_3.c \
	sort_part_4.c

SRCSBO= checker.c \
	checker_utils.c \
	check_error_bonus.c \
	push_bonus.c \
	rotate_bonus.c \
	rrotate_bonus.c \
	swap_bonus.c \
	get_next_line.c \
	utils_bonus.c \
	init_bonus.c

INC_DIR= ./

OBJS= ${SRCS:.c=.o}

OBJS2 = ${SRCSBO:.c=.o}

CC=	cc
FLAGS=	-Wall -Wextra -Werror -g3
RM=	rm -f

all: $(NAME)

${NAME}: ${OBJS}
	$(CC) $(FLAGS) $(OBJS) -o ${NAME}

bonus:  ${OBJS2}
	$(CC) $(FLAGS) $(OBJS2) -o checker

AR= ar rcs

%.o: %.c 
	${CC} ${FLAGS} -MMD -MP -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJS2}

fclean: clean
	${RM} ${NAME} *.d
	${RM} ${NAME} checker

re: fclean all


.PHONY: all clean fclean re bonus
