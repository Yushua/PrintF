/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 19:41:47 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** str c = character "g" yes +,  no 0 **
** str s = string "hello"
** int p = pointer adress ptr
** int d = signed integer (dec)
** int i = signed integer (dec) 276447232
** int u = unsigned integer (dec)
** int x = unsigned integer (hex)
** int X = unsigned integer (hex) (CAPS)
** % = '%' start. look after that %%
**
** 0 = width but spaces are zero
** *. = precision but an integer va_arg before convergance both in and str, jsut different
** * = width but another integer  char when you see * use va_arg
** . = the input stand at location 10,
** - = takes it on the left instead on the right
*/
	
#define	INPUT "char: %c | str: %s | ptr: %p | int: %d | uit: %u | Hex: %X | hex: %x | epc: %%", c, str, &ptr, i, ui, hex, hhex
// #define QUEST "%0*i", -7, -54
int     main(void)
{
	char			c;
	char			*str;
	int				ptr;
	int				i;
	unsigned int	ui;
	int				hex;
	int				hhex;

	c = 'g';
	str = "he";
	ptr = 123;
	i = 31415;
	ui = -10;
	hex = 276447232;
	hhex = 276447232;
	ft_printf("own\n");
	ft_printf(INPUT);
	printf("|\nprintf\n");
	printf(INPUT);
	printf("|\n");
	while (i)
	{
		hex = 0;
	}
	return (0);

}

//gcc libft/*.c *.c -g -fsanitize=address
//gcc *.c -g
//gcc *.c -g -fsanitize=address

//printf("%i|\n|", (*print)->error);
//printf("%s|\n|",(*print)->flag_str);
/*
printf("|input|%s|\n", (*print)->input_str);
printf("|empty|%s|\n", (*print)->flag_str);

//printf("%s|\n|", (*print)->input_str);

	char			c;
	char			*str;
	int				ptr;
	int				i;
	unsigned int	ui;
	int				hex;
	int				hhex;

	c = 'g';
	str = "he";
	ptr = 123;
	i = 31415;
	ui = -10;
	hex = 276447232;
	hhex = 1235445;
*/