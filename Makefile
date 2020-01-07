# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/01 10:51:58 by ybakker        #+#    #+#                 #
#    Updated: 2020/01/07 21:51:54 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a

SRCS		=	ft_empty_str.c \
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

OFILES = 		$(SRCS:.c=.o)
FLAGS			=	-Wall -Wextra -Werror -g 
FLAGS_ADRESS    =   -Wall -Wextra -Werror -g -fsanitize=address
AR_COMMAND		=	ar rcsv

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<
	
$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	@gcc $(FLAGS_ADRESS) -o $@ -c $<

address: $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all