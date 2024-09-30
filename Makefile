# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 14:56:58 by jrocha-f          #+#    #+#              #
#    Updated: 2024/05/02 14:56:58 by jrocha-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SORCES = push_swap.c stack_init.c stack_utils.c check_args.c stack_del.c\
		is_sorted.c lst_values.c command_swap.c command_rotate.c\
		command_revrotate.c command_push.c sort_utils.c sort.c cost_to_push.c\
		rotating_combo.c rotating_combo2.c

OBJ = $(SORCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SUBDIRS = libft

all: $(NAME) libraries

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) libraries
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

.PHONY: libraries
libraries:$(SUBDIRS)

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm -f $(OBJ)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done

fclean: clean
	rm -f $(NAME)
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir fclean; done

re: fclean all

.PHONY: all clean fclean re
