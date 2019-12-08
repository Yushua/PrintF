/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 16:43:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** c = character "g" yes +,  no 0
** s = string "hello"
** p = pointer adress ptr
** d = signed integer (dec)
** i = signed integer (dec)
** u = unsigned integer (dec)
** x = unsigned integer (hex)
** X = unsigned integer (hex) (CAPS)
** % = '%' start. look after that %%
**
** .* = precision but an integer
** 0 = width but spaces are zero
** * = width but another integer
** .
** + = normal
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
	printf("%00+-6i \n", 1);
	//printf("%c%c%c%c", 'hellz', 'b', 'c', 'd');
	//printf("Preceding with blanks: \n %0c \n %+0s \n %0p \n %0d \n %0i \n %0u \n %0x \n %0X \n %0% \n ", 'a', "hello", 123, 123, 123, 123, 132, 132, 123);
	//printf("Preceding with blanks:\n%0d\n%0i\n%0u\n%0x\n%0X\n%0%\n",123, 123, 123, 123, 123, 123, 123);
	//printf("|%d|", printf(INPUT));
	//ft_printf("|%d|", printf(INPUT));
	return (0);
}

//make one long string, put it in trim and use \n as the cut, the print that out using write, character by character