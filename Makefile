# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayako <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 15:01:39 by cayako            #+#    #+#              #
#    Updated: 2020/03/04 18:33:45 by cayako           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR	= ./src
INCDIR	= ./inc
OBJDIR  = ./obj/
RAW_DIRS = $(shell find $(SRCDIR) -mindepth 1 -type d)
SRCDIRS = $(RAW_DIRS:./src/%=%)

FT_IS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_iswhitespace.c
FT_MEM		= ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memdel.c ft_memmove.c ft_memset.c
FT_LST		= ft_lstadd.c ft_lstdelcontent.c ft_lstmap.c ft_lstpushf.c \
				ft_lststrtoarr.c ft_lstcut.c ft_lstdelone.c ft_lstnew.c \
				ft_lstsize.c ft_lstdel.c ft_lstiter.c ft_lstpushb.c \
				ft_lststrsplit.c
FT_PUT		= ft_putchar.c ft_putendl.c ft_putnbr.c ft_putnendl.c ft_putstr.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnstr.c \
				ft_putstr_fd.c
FT_STR		= ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strlen.c \
				ft_strncat.c ft_strnequ.c ft_strrchr.c ft_strsub.c \
				ft_strchr.c ft_strcpy.c ft_strequ.c ft_strjoin.c ft_strmap.c \
				ft_strncmp.c ft_strnew.c ft_strsplit.c ft_strtrim.c \
				ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c ft_strmapi.c \
				ft_strncpy.c ft_strnstr.c ft_strstr.c
FT_OTHERS	= ft_atoi.c ft_atoi_n.c ft_bzero.c  ft_itoa.c ft_itoa_mem_d.c \
				ft_tolower.c ft_toupper.c
GNL			= get_next_line.c
PRNTF		= ft_parsing.c ft_pf_utils.c ft_printf.c ft_put_digit.c ft_put_f.c \
   				ft_put_oxup.c ft_put_src.c ft_putarg.c
SRCS		= $(FT_IS) $(FT_MEM) $(FT_LST) $(FT_PUT) $(FT_STR) $(FT_OTHERS) \
				$(PRNTF)

SRC		= $(addprefix $(SRCDIR)/is/,$(FT_IS))
SRC		+= $(addprefix $(SRCDIR)/mem/,$(FT_MEM))
SRC		+= $(addprefix $(SRCDIR)/lst/,$(FT_LST))
SRC		+= $(addprefix $(SRCDIR)/put/,$(FT_PUT))
SRC		+= $(addprefix $(SRCDIR)/str/,$(FT_STR))
SRC		+= $(addprefix $(SRCDIR)/others/,$(FT_OTHERS))
SRC		+= $(addprefix $(SRCDIR)/get_next_line/,$(GNL))
SRC		+= $(addprefix $(SRCDIR)/ft_printf/,$(PRNTF))

#OBJ		= $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS	= libft.h get_next_line.h ft_printf.h
INC		= $(addprefix $(INCDIR)/,$(INCS))

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(addprefix $(OBJDIR)/,$(SRCDIRS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo $(SRC)
	sleep 5
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ) | obj
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
