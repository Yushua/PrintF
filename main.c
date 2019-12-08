/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:41:43 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** c = character "g"
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
** - = width but spaces after
** 0 = width but spaces are zero
** * = width but another integer
** - = srtarts str on the left
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
	printf("%% \n");
	printf("%p \n", &ptr);
	printf("Preceding with blanks: %u \n", 1977);
	printf("|%d|", printf(INPUT));
	//ft_printf("|%d|", printf(INPUT));
	return (0);
}
