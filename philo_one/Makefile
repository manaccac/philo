# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 13:08:51 by jdel-ros          #+#    #+#              #
#    Updated: 2021/02/16 10:19:59 by jdel-ros         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER =	philo_one.h

SRCS =		philo_one.c routine.c ft_conv_to_ms.c utils.c eat.c sleep.c \
			ft_check_die.c messages.c init.c routine_two.c \

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
