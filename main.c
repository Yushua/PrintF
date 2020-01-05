/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/05 15:42:09 by ybakker       ########   odam.nl         */
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
	ui = -10;
	hex = 276447232;
	hhex = 1235445;
	printf("%06s\n", str);
	ft_printf("%06s\n", str);
	//printf("%c\n", c);
	//ft_printf("%c\n\n", c);
	//printf("%s\n", str);
	//ft_printf("%s\n\n", str);
	//printf(INPUT);
	//printf("\n");
	//ft_printf(INPUT);
	//printf("%p\n", &ptr);
	//printf("%06i\n", i);
	//ft_printf("%06i\n\n", i);
	//printf("%c\n", c);
	//ft_printf("%c\n\n", c);
	return (0);
}

//everytime you write you increase th len

//gcc libft/*.c *.c -g

	//printf("hello \n");
	//ft_printf("hello\n");
	//printf("%.3i\n%3.i\n%3.3i%.03i\n", 10, 10, 10, 10);
	//printf("precision1\n");
	//printf("%-6i\n%-06.i\n%-*.20i\n%.20i\n", 10, 10, 5, 10, 10);
	//printf("min\n");
	//printf("%*.i\n", 10, 10); //first - and 0 then the rest
	//printf("%-03.i\n", 10);
	//printf("width, no more -, zero and numbers\n");
	//printf("%01.10i\n", 10);// for min, check if ther ei somethign ebhind dot
	//printf("%*i\n%*.20i\n\n%5.i\n%5.10i\n\n%5i\n", 10, 10, 10, 10, 10, 10, 10);
	//ft_printf("%%\nhello\n", 10);
	//ft_printf("%5.10i\n", 10, 10);
	//ft_printf("%%\n");
	//printf("%c", "a");
	//ft_printf("%c", "a");