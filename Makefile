# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aogbi <aogbi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 10:08:49 by aogbi             #+#    #+#              #
#    Updated: 2024/04/11 01:59:44 by aogbi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
LIBFTDIR = Libft
FT_PRINTFDIR = printf
LIBS = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf
SRCS = \
	main.c
OBJS =$(SRCS:.c=.o)
EXEC = push_swap

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(FT_PRINTFDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re