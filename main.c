/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 14:54:52 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 14:31:41 by ybakker       ########   odam.nl         */
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
#define INPUT "%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&u01,&u02,&u03,&u04,&u05,&u06,&u07,&u08,&u09,&u10,&u11,&u12
#define INPUT1 "%60p%60p%60p%60p%60p%60p%60p%60p%60p%60p%60p%60p",&u01,&u02,&u03,&u04,&u05,&u06,&u07,&u08,&u09,&u10,&u11,&u12
#define INPUT2 "|%32p|%32p|%32p|%32p|%32p|%32p|%32p|%32p|%32p|%32p|%32p|%32p|",&u01,&u02,&u03,&u04,&u05,&u06,&u07,&u08,&u09,&u10,&u11,&u12
#define INPUT3 "%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&u01,&u02,&u03,&u04,&u05,&u06,&u07,&u08,&u09,&u10,&u11,&u12
// #define INPUT4
int     main(void)
{

	static char	u01;
	static unsigned char u02;
	static short u03;
	static unsigned short u04;
	static int u05;
	static unsigned int u06;
	static long u07;
	static unsigned long u08;
	static long long u09;
	static unsigned long long u10;
	static char *u11;
	static void *u12;

	ft_printf("|");
	ft_printf(INPUT);
	ft_printf("]\n|");
	printf(INPUT);
	ft_printf("]\n");
	ft_printf("|");
	ft_printf(INPUT1);
	ft_printf("]\n|");
	printf(INPUT1);
	ft_printf("]\n");
	ft_printf("|");
	ft_printf(INPUT2);
	ft_printf("]\n|");
	printf(INPUT2);
	ft_printf("]\n");
	ft_printf("|");
	ft_printf(INPUT3);
	ft_printf("]\n|");
	printf(INPUT3);
	ft_printf("]\n");
	// ft_printf("|");
	// ft_printf(input4);
	// ft_printf("|\n|");
	// printf(input4);
	// ft_printf("|\n");
	while (1)
	{
		0;
	}
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