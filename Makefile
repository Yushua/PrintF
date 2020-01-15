# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/01 10:51:58 by ybakker        #+#    #+#                 #
#    Updated: 2020/01/15 20:51:24 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS		=	ft_atoi.c \
				ft_exemption.c \
				ft_hex.c \
				ft_itoa.c \
				ft_long_itoa.c \
				ft_precision.c \
				ft_print_hex_write.c \
				ft_print_int_write.c \
				ft_print_p_write.c \
				ft_print_str_write.c \
				ft_print_str.c \
				ft_printf.c \
				ft_strdup.c \
				ft_struct_zero.c \
				ft_utills1.c \
				ft_utills2.c \
				ft_utills3.c \
				ft_width.c \
				

OFILES = 		$(SRCS:.c=.o)
FLAGS			=	-Wall -Wextra -Werror 
AR_COMMAND		=	ar rcsv

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<
	
$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	@gcc $(FLAGS_ADRESS) -o $@ -c $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

g:
	gcc *.c -g 

a:
	./a.out

re: fclean all