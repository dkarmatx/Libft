# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgranule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:36:01 by hgranule          #+#    #+#              #
#    Updated: 2019/04/15 09:08:29 by hgranule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra

HDRS = $(CUR_DIR)/includes
SRCS = $(CUR_DIR)/srcs
CUR_DIR = $(shell pwd)

FUNCTIONS = $(shell grep -oE 'ft_[^()]+' ./includes/libft.h)
CS = $(patsubst %, %.c, $(FUNCTIONS))
BINS = $(patsubst %, %.o, $(FUNCTIONS))



all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(patsubst %, $(SRCS)/%, $(CS)) -I$(HDRS)
	@ar rc $(NAME) $(BINS)
	@ranlib $(NAME)

clean:
	@rm -f $(BINS)

fclean: clean
	@rm -f $(NAME)

re: fclean all