/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 17:17:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** str c = character "g" yes +,  no 0
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

#define	INPUT "char: %c | str: %s | ptr: %p | int: %d | uit: %u | hex: %x | Hex: %X | epc: %%", c, str, &ptr, i, ui, hex, hhex

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
	str = "hello";
	ptr = 123;
	i = 31415;
	ui = -1;
	hex = 1235454;
	hhex = 1235454;
	
	//printf("hello \n");
	//ft_printf("hello\n");
	//printf("%.3i\n%3.i\n%3.3i%.03i\n", 10, 10, 10, 10);
	//printf("precision1\n");
	//printf("%-6i\n%-06.i\n%-*.20i\n%.20i\n", 10, 10, 5, 10, 10);
	//printf("min\n");
	//printf("%*.i\n", 10, 10); //first - and 0 then the rest
	//printf("%-03.i\n", 10);
	//printf("width, no more -, zero and numbers\n");
	printf("hello\nhello\n");
	ft_printf("hello\nhello\n");
	//ft_printf("%%\n");
	//printf("%c", "a");
	//ft_printf("%c", "a");
	return (0);
}
