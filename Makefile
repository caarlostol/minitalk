# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 13:56:24 by chayashi          #+#    #+#              #
#    Updated: 2024/03/08 16:08:50 by chayashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRCS = server.c client.c
BONUS_SRCS = server_bonus.c client_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft

server: server.o
	cc -Wall -Wextra -Werror -o server server.o libft/libft.a

client: client.o
	cc -Wall -Wextra -Werror -o client client.o libft/libft.a

server_bonus: server_bonus.o
	cc -Wall -Wextra -Werror -o server_bonus server_bonus.o libft/libft.a

client_bonus: client_bonus.o
	cc -Wall -Wextra -Werror -o client_bonus client_bonus.o libft/libft.a

$(NAME): $(OBJS) libft/libft.a server client

bonus: $(BONUS_OBJS) libft/libft.a server_bonus client_bonus

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -rf $(NAME) $(OBJS) $(BONUS_OBJS) server client server_bonus client_bonus

re: fclean all
