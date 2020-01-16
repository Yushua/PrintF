/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/16 22:50:01 by ybakker       ########   odam.nl         */
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
	
// #define	INPUT "Hex: %X | hex: %x | epc: %%", hex, hhex
#define INPUT "%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12

int     main(void)
{
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	int				i;
	int				hex;

	i = 31415;
	hex = 276447232;

	ft_printf("own\n");
	ft_printf(INPUT);
	printf("\nprintf\n");
	printf(INPUT);
	printf("\n");
	while (i)
	{
		hex = 0;
	}
	return (0);
}

//		printf("\n|%i|\n|", (*print)->width_nb);
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