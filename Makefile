# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgranule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:36:01 by hgranule          #+#    #+#              #
#    Updated: 2019/05/03 08:57:54 by hgranule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
WORK_SPACE = $(shell pwd)
CC = gcc
CCFLAGS = -Wall -Werror -Wextra

H_DIR = $(WORK_SPACE)/includes
TMP_DIR = $(WORK_SPACE)/tmps
HDRS = $(shell ls $(H_DIR))

FT_CTYPE_D =	$(WORK_SPACE)/srcs/ft_ctype
FT_CTYPE_S =	$(patsubst %, $(FT_CTYPE_D)/%.c, $(FT_CTYPE_F))
FT_CTYPE_F =	ft_toupper ft_tolower ft_isalpha \
				ft_isascii ft_isdigit ft_isalnum \
				ft_isprint ft_isspace

FT_IO_D =		$(WORK_SPACE)/srcs/ft_io
FT_IO_S =		$(patsubst %, $(FT_IO_D)/%.c, $(FT_IO_F))
FT_IO_F =		ft_putchar ft_putstr ft_putendl \
				ft_putnbr ft_putll_base_fd ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd

FT_LIST_D =		$(WORK_SPACE)/srcs/ft_list
FT_LIST_S =		$(patsubst %, $(FT_LIST_D)/%.c, $(FT_LIST_F))
FT_LIST_F =     ft_lstnew ft_lstdelone ft_lstdel \
				ft_lstadd ft_lstiter ft_lstmap

FT_MEM_D =		$(WORK_SPACE)/srcs/ft_mem
FT_MEM_S =		$(patsubst %, $(FT_MEM_D)/%.c, $(FT_MEM_F))
FT_MEM_F =		ft_memdel ft_memalloc ft_memset \
				ft_bzero ft_memcpy ft_memccpy \
				ft_memmove ft_memchr ft_memcmp \
				ft_realloc ft_hexdump ft_memdup

FT_STRING_D =	$(WORK_SPACE)/srcs/ft_string
FT_STRING_S =	$(patsubst %, $(FT_STRING_D)/%.c, $(FT_STRING_F))
FT_STRING_F =	ft_strnew ft_strdup ft_strchr \
				ft_strrchr ft_strstr ft_strnstr \
				ft_strcpy ft_strncpy ft_strcat \
				ft_strncat ft_strlcat ft_strdel \
				ft_strclr ft_striter ft_striteri \
				ft_strmap ft_strmapi ft_strlen \
				ft_strnlen ft_strcmp ft_strncmp \
				ft_strequ ft_strnequ ft_strsub \
				ft_strjoin ft_strtrim ft_strsplit \
				ft_lltoa_base ft_itoa ft_atoll_base \
				ft_atoi_base ft_atoi ft_countw_delim

all: $(NAME)

tmp_dir:
	@if ! [ -d $(TMP_DIR) ]; then mkdir $(TMP_DIR); fi;

ft_string: tmp_dir
	$(foreach cs, $(FT_STRING_S), $(shell if ! [ -f $(patsubst $(FT_STRING_D)/%.c, $(TMP_DIR)/%.o, $(cs)) ]; \
	then $(CC) $(CCFLAGS) -c $(cs) -I $(H_DIR); \
	mv $(patsubst $(FT_STRING_D)/%.c, $(WORK_SPACE)/%.o, $(cs)) $(TMP_DIR)/; \
	fi;))

ft_ctype: tmp_dir
	$(foreach cs, $(FT_CTYPE_S), $(shell if ! [ -f $(patsubst $(FT_CTYPE_D)/%.c, $(TMP_DIR)/%.o, $(cs)) ]; \
	then $(CC) $(CCFLAGS) -c $(cs) -I $(H_DIR); \
	mv $(patsubst $(FT_CTYPE_D)/%.c, $(WORK_SPACE)/%.o, $(cs)) $(TMP_DIR)/; \
	fi;))

ft_mem: tmp_dir
	$(foreach cs, $(FT_MEM_S), $(shell if ! [ -f $(patsubst $(FT_MEM_D)/%.c, $(TMP_DIR)/%.o, $(cs)) ]; \
	then $(CC) $(CCFLAGS) -c $(cs) -I $(H_DIR); \
	mv $(patsubst $(FT_MEM_D)/%.c, $(WORK_SPACE)/%.o, $(cs)) $(TMP_DIR)/; \
	fi;))

ft_list: tmp_dir
	$(foreach cs, $(FT_LIST_S), $(shell if ! [ -f $(patsubst $(FT_LIST_D)/%.c, $(TMP_DIR)/%.o, $(cs)) ]; \
	then $(CC) $(CCFLAGS) -c $(cs) -I $(H_DIR); \
	mv $(patsubst $(FT_LIST_D)/%.c, $(WORK_SPACE)/%.o, $(cs)) $(TMP_DIR)/; \
	fi;))

ft_io: tmp_dir
	$(foreach cs, $(FT_IO_S), $(shell if ! [ -f $(patsubst $(FT_IO_D)/%.c, $(TMP_DIR)/%.o, $(cs)) ]; \
	then $(CC) $(CCFLAGS) -c $(cs) -I $(H_DIR); \
	mv $(patsubst $(FT_IO_D)/%.c, $(WORK_SPACE)/%.o, $(cs)) $(TMP_DIR)/; \
	fi;))

$(NAME):
	@$(MAKE) ft_string
	@$(MAKE) ft_ctype
	@$(MAKE) ft_mem
	@$(MAKE) ft_list
	@$(MAKE) ft_io
	@ar rc $(NAME) $(TMP_DIR)/*.o
	@ranlib $(NAME)

clean:
	@rm -rf $(TMP_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
