# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgranule <hgranule@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:36:01 by hgranule          #+#    #+#              #
#    Updated: 2019/11/29 19:25:32 by hgranule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
WORK_SPACE = $(shell pwd)
CC = gcc
CCFLAGS = -Wall -Werror -Wextra -g
EMPTY =
TMP =

H_DIR = $(WORK_SPACE)/includes
O_DIR = $(WORK_SPACE)/objs
A_DIR = $(WORK_SPACE)/alibs
C_DIR = $(WORK_SPACE)/srcs

STD_LIB =		ctype io list dlist mem string gnl lbuff avltr dstr dbg

STD_LIBS =		$(patsubst %, libft%.a, $(STD_LIB))
LIBS =			$(patsubst %, $(A_DIR)/%, $(STD_LIBS))
ALL_O =			$(foreach lib, $(shell echo $(STD_LIB) | tr a-z A-Z), $(patsubst %, $(O_DIR)/%.o, $($(lib))))

GNLO =			$(patsubst %, $(O_DIR)/%.o, $(GNL))
GNLS =			$(patsubst %, $(C_DIR)/%.c, $(GNL))
GNL =			get_next_line

DBGO =			$(patsubst %, $(O_DIR)/%.o, $(DBG))
DBGS =			$(patsubst %, $(C_DIR)/%.c, $(DBG))
DBG =			dbg_timer dbg_timer_points

DSTRO =			$(patsubst %, $(O_DIR)/%.o, $(DSTR))
DSTRS =			$(patsubst %, $(C_DIR)/%.c, $(DSTR))
DSTR =			dstr_insert dstr_mem dstr_slice dstr_swpc dstr_srch

CTYPEO =		$(patsubst %, $(O_DIR)/%.o, $(CTYPE))
CTYPES =		$(patsubst %, $(C_DIR)/%.c, $(CTYPE))
CTYPE =			ft_toupper ft_tolower ft_isalpha \
				ft_isascii ft_isdigit ft_isalnum \
				ft_isprint ft_isspace

IOO =			$(patsubst %, $(O_DIR)/%.o, $(IO))
IOS =			$(patsubst %, $(C_DIR)/%.c, $(IO))
IO =			ft_putchar ft_putstr ft_putendl \
				ft_putnbr ft_putll_base_fd ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
				ft_hexdump \
				\
				ft_strlen
				# IMPORT FUNCTIONS

LISTO =			$(patsubst %, $(O_DIR)/%.o, $(LIST))
LISTS =			$(patsubst %, $(C_DIR)/%.c, $(LIST))
LIST =			ft_lstnew ft_lstdelone ft_lstdel \
				ft_lstadd ft_lstiter ft_lstmap \
				\
				ft_memdel ft_memcpy
				# IMPORT FUNCTIONS

DLISTO =		$(patsubst %, $(O_DIR)/%.o, $(DLIST))
DLISTS =		$(patsubst %, $(C_DIR)/%.c, $(DLIST))
DLIST =			ft_dlstnew ft_dlstpush ft_dlstunshift \
				ft_dlstget ft_dlstrget ft_dlstinsert \
				ft_dlstrmelem ft_dlstcut ft_dlstdel \
				ft_dlstshift ft_dlstswap ft_dlst_gnsort \
				ft_dlst_rgnsort ft_dlst_count ft_dlst_maparr \
				\
				ft_memdup ft_memcpy
				# IMPORT FUNCTIONS

MEMO =			$(patsubst %, $(O_DIR)/%.o, $(MEM))
MEMS =			$(patsubst %, $(C_DIR)/%.c, $(MEM))
MEM =			ft_memdel ft_memalloc ft_memset \
				ft_bzero ft_memcpy ft_memccpy \
				ft_memmove ft_memchr ft_memcmp \
				ft_realloc ft_memdup

LBUFFO =		$(patsubst %, $(O_DIR)/%.o, $(LBUFF))
LBUFFS =		$(patsubst %, $(C_DIR)/%.c, $(LBUFF))
LBUFF =			ft_lbuffer_io

AVLTRO =		$(patsubst %, $(O_DIR)/%.o, $(AVLTR))
AVLTRS =		$(patsubst %, $(C_DIR)/%.c, $(AVLTR))
AVLTR =			ft_avl_balance_blt ft_avl_edit_blt ft_avl_srch_blt ft_avl_utils_blt \
				ft_avl_api_del ft_avl_api_info ft_avl_api_nodecr

STRINGO =		$(patsubst %, $(O_DIR)/%.o, $(STRING))
STRINGS =		$(patsubst %, $(C_DIR)/%.c, $(STRING))
STRING =		ft_strnew ft_strdup ft_strchr \
				ft_strrchr ft_strstr ft_strnstr \
				ft_strcpy ft_strncpy ft_strcat \
				ft_strncat ft_strlcat ft_strdel \
				ft_strclr ft_striter ft_striteri \
				ft_strmap ft_strmapi ft_strlen \
				ft_strnlen ft_strcmp ft_strncmp \
				ft_strequ ft_strnequ ft_strsub \
				ft_strjoin ft_strtrim ft_strsplit \
				ft_lltoa_base ft_itoa ft_atoll_base \
				ft_atoi_base ft_atoi ft_countw_delim ft_strccpy \
				ft_strsplits ft_strcate ft_mem_mem \
				\
				ft_isspace ft_memchr ft_bzero ft_memcpy \
				ft_memdel ft_memalloc ft_memcmp
				# IMPORT FUNCTIONS

all: $(NAME)

$(NAME): $(ALL_O)
	@ar rc $(NAME) $(ALL_O);
	@ranlib $(NAME);

o_dir:
	@if ! [ -d $(O_DIR) ]; then mkdir $(O_DIR); fi;

a_dir: o_dir
	@if ! [ -d $(A_DIR) ]; then mkdir $(A_DIR); fi;

# $(O_DIR)/%.o: $(C_DIR)/%.s
# 	@make o_dir
# 	@echo "\033[1m\033[38;2;0;60;255mCompiling : \033[7m$<\033[0m\033[1m\033[38;2;0;60;255m <<\033[0m";
# 	@$(HOME)/.brew/bin/nasm -f macho64 $< -o $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	@make o_dir
	@echo "\033[1m\033[38;2;0;60;255mCompiling : \033[7m$<\033[0m\033[1m\033[38;2;0;60;255m <<\033[0m";
	@$(CC) $(CCFLAGS) -c $< -o $@ -I$(H_DIR);

libft%.a: a_dir
	$(eval EMPTY = $(shell echo $(patsubst libft%.a, %O, $@) | tr a-z A-Z))
	@echo "$@ :\n";
	@make $($(EMPTY));
	@ar rc $(A_DIR)/$@ $($(EMPTY));
	@ranlib $(A_DIR)/$@;
	@echo "\n\033[1m\033[38;2;0;255;0m$@ is compiled\033[0m\n";

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm -rf $(A_DIR)
	@rm -f $(NAME)

re_libft%.a:
	$(eval EMPTY = $(shell echo $(patsubst re_libft%.a, %O, $@) | tr a-z A-Z))
	$(eval TMP = $(patsubst re_%, %, $@))
	@rm -f $(A_DIR)/$(TMP);
	@rm -f $($(EMPTY));
	@make $(TMP);

re: fclean all