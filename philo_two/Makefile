# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 13:08:51 by jdel-ros          #+#    #+#              #
#    Updated: 2021/02/15 12:00:12 by jdel-ros         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER =	philo_two.h

SRCS =		philo_two.c routine.c ft_conv_to_ms.c utils.c eat.c sleep.c \
			ft_check_die.c messages.c init.c routine_two.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_two.a

RM		=	rm -f

FLAGS	=	-Wall -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) $(NAME) -o philo_two
clean:
	@$(RM) $(OBJS) philo_two
fclean:	clean
	@$(RM) $(NAME)
re: 	fclean all
