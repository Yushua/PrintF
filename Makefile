# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/01 10:51:58 by ybakker        #+#    #+#                 #
#    Updated: 2020/01/06 15:23:42 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a
LIBFT_A =	libft.a

LIB_DIR =	libft/
SRC_DIR =	srcs/

SRC		=	empthy_str.c \
			ft_hex.c \
			ft_long_itoa.c \
			ft_place_zero.c \
			ft_precision.c \
			ft_print_flag.c \
			ft_print_str.c \
			ft_print_write.c \
			ft_printf.c \
			ft_save_write.c \
			ft_struct_zero.c \

CFIND =		$(Crc:%=$(SRC_DIR)%)
OFILE =		$(CFILE:%.c=%.o)

all: $(OBJ_DIR) $(NAME)

OFILES			=	$(SRC:%.c=%.o)
BONUS_OFILES	=	$(BONUS_SRC:%.c=%.o)
FLAGS			=	-Wall -Wextra -Werror
AR_COMMAND		=	ar rcsv

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	@gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
