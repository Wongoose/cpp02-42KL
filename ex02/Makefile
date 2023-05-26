# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:04:34 by zwong             #+#    #+#              #
#    Updated: 2023/05/26 13:04:36 by zwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = operators
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(SRCS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $@

clean : 
	rm $(OBJS)

fclean : clean 
	rm -rf $(NAME)

re : fclean all
