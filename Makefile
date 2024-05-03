# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 06:30:57 by aogbi             #+#    #+#              #
#    Updated: 2024/05/03 14:31:33 by aogbi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBFTDIR = Libft
FT_PRINTFDIR = printf
LIBS = -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf
SRCS = \
	main.c operations.c parsing.c clean.c push_to_a.c \
	push_to_b.c
OBJS =$(SRCS:.c=.o)
EXEC = push_swap

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(FT_PRINTFDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re