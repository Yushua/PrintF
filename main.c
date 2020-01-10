/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 13:02:17 by ybakker       ########   odam.nl         */
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
#define QUEST "%.7s", "hello"
//#define QUEST "%.d\n", 0
//#define QUEST "%09.*p", -15, 2764472 //when the second * s a min, then you just print input_str
int     main(void)
{
	//test 426
	ft_printf("own\n");
	ft_printf("|");
	ft_printf(QUEST);
	printf("|\n");
	printf("printf\n|");
	printf(QUEST);
	printf("|");
	printf("\n");
	return (0);
}
//	if (width >= (*print)->width_str)
//		width = (*print)->width_str;
//everytime you write you increase th len

//gcc libft/*.c *.c -g -fsanitize=address
//gcc *.c -g
//gcc *.c -g -fsanitize=address
/*
printf("|input|%s|\n", (*print)->input_str);
printf("|empty|%s|\n", (*print)->flag_str);
 */

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
/*
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