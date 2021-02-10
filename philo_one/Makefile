# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 13:08:51 by jdel-ros          #+#    #+#              #
#    Updated: 2021/02/10 11:46:05 by manaccac         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER =	philo_one.h

SRCS =		philo_one.c routine.c ft_conv_to_ms.c utils.c eat.c sleep.c think.c \
			ft_check_die.c messages.c init.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_one.a

RM		=	rm -f

FLAGS	=	-Wall -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) $(NAME) -o philo_one
clean:
	@$(RM) $(OBJS) philo_one
fclean:	clean
	@$(RM) $(NAME)
re: 	fclean all
