/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 16:53:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	
	printf("only   .|%5.i \n", 10);
	return (0);
}

//make one long string, put it in trim and use \n as the cut, the print that out using write, character by character

//hwo does . work?
/*
	//printf("i dot 0 %08.6i \n", 1);
	//printf("c dot 0 %06s \n", "hello");
	//printf("i dot 0%08.6i \n", 1);
	//printf("c dot 0%06s \n", "hello");
	//printf("i dot 0%08.6i \n", 1);
	//printf("c dot width 0%06s \n", "hello");
	//printf("only *  |%3i \n", 1); //star test int
	//printf("only *  |%*i \n",3, 1); //star test
	//printf("only *  .|%3.5i \n", 1); //star test int
	//printf("only   .|%5.i \n", 10); //star test number for is empty line
	//printf("only   .|%.5i \n", 1); //star test number after is zero
	//printf("only 0  .|%05.6i \n", 1); //star test int iz . is is 0 meaning, . becomes bzero and 0 becomes memset " "
	//printf("only -0 .|%-05.6i \n", 1); //star test int iz . is is 0 meaning, . becomes bzero and 0 becomes memset " "
	//printf("only 0  .|%05.6i \n", 1234);
	//printf("only -0 .|%3.i \n", 1234);
	//printf("only.|%.3s \n", "hello");
	//printf("only.|%20.3s \n", "hello");
	//printf("only *  |%3i \n", 1); //star test int
	//printf("only *  |%*i \n",3, 1); //star test
	//printf("only *- |%3i \n", -1); //star test
	//printf("only *- |%3-i \n", -1); //star test
	//printf("only *- |%*i \n",3, -1); //star test
	//printf("hello %i \n", 1);
	//printf("%20.7s \n", "hier staat tekst");
	//printf("%20.12i \n", 100000); // 20 spaces big, the n  creates 7 spaces of 0 then places the in there
	//printf("%20.4i \n", 100000);
	//printf("only .%*i \n",20, 100000);
	//printf("%*.7s \n", 20, "hier staat tekst");
	//printf("%-*.7i\n", 20, 100000000000000);
	//printf("%c\n%c\n%c\n%c\n", 'a', 'b', 'c', 'd');
	//printf("Preceding with blanks: \n %0c \n %+0s \n %0p \n %0d \n %0i \n %0u \n %0x \n %0X \n %0% \n ", 'a', "hello", 123, 123, 123, 123, 132, 132, 123);
	//printf("Preceding with blanks:\n%0d\n%0i\n%0u\n%0x\n%0X\n%0%\n",123, 123, 123, 123, 123, 123, 123);
	//printf("|%d|", printf(INPUT));
	//ft_printf("|%d|", printf(INPUT));
*/