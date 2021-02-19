# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 13:08:51 by jdel-ros          #+#    #+#              #
#    Updated: 2021/02/18 13:23:04 by jdel-ros         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER =	philo_three.h

SRCS =		philo_three.c routine.c ft_conv_to_ms.c utils.c eat.c sleep.c \
			ft_check_die.c messages.c init.c proc.c check_thread.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_three.a

RM		=	rm -f

FLAGS	=	-Wall -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) $(NAME) -o philo_three
clean:
	@$(RM) $(OBJS) philo_three
fclean:	clean
	@$(RM) $(NAME)
re: 	fclean all
