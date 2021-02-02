# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 13:08:51 by jdel-ros          #+#    #+#              #
#    Updated: 2021/02/02 13:50:14 by jdel-ros         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER =	philo_one.h

SRCS =		philo_one.c

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_one.a

RM		=	rm -f

FLAGS	=	-Wall -Wextra

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) $(NAME)
clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
re: 	fclean all