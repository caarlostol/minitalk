# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:56:24 by chayashi          #+#    #+#              #
#    Updated: 2024/03/07 15:22:54 by chayashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft

server: server.o
	cc -Wall -Wextra -Werror -o server server.o libft/libft.a

client: client.o
	cc -Wall -Wextra -Werror -o client client.o libft/libft.a


$(NAME): $(OBJS) libft/libft.a server client


clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -rf $(NAME) $(OBJS) server client

re: fclean all
