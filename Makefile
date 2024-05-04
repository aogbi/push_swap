# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 06:30:57 by aogbi             #+#    #+#              #
#    Updated: 2024/05/04 22:18:03 by aogbi            ###   ########.fr        #
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

BSRCS = \
	checker.c operations.c parsing.c clean.c \
	get_next_line.c get_next_line_utils.c

OBJS =$(SRCS:.c=.o)
BOBJS =$(BSRCS:.c=.o)
NAME = push_swap
BNAME = checker

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
NC=\033[0m

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	@make -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make bonus -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make -C printf | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)Compilation successful$(NC)"

$(BNAME): $(BOBJS)
	@make -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make bonus -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make -C printf | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -o $@
	@echo "$(GREEN)Compilation successful$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling...$(NC)"
	@$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(FT_PRINTFDIR) -c $< -o $@

clean:
	@make clean -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make clean -C printf | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@echo "$(RED)Cleaning objects...$(NC)"
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@make fclean -C Libft | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@make fclean -C printf | sed '/^make\[1\]: Entering directory/d'  | sed '/^make\[1\]: Leaving directory/d'
	@echo "$(BLUE)Cleaning...$(NC)"
	@rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re