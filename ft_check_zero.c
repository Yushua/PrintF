/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 21:36:49 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 14:33:47 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	ft_print_zero(char str) //str has the number of spaces you need to have empty
{
	int		i;

	i = atoi(str);
	free(str);
	str = ((char *)malloc(sizeof(char) * (i + 1));
	str = ft_bzero(str, i);	//use memset for the heoveelheid spaces
	(*print)->flags = str;
	free(str);
}

t_print		ft_check_zero(t_print **print, const char *format, int  i, va_list ap)
{
	char	str;
	int		j;
	int		b;
	
	i++; //one furder
	b = i; //b is the beginning
	j = 0;
	while (format[i] => '0' || format[i] =< '9') //get the numbers out of format of how long
	{
		j++;
		i++;
	}
	str = ((char *)malloc(sizeof(char) * (j + 1));//malloc them in a string, j now how big it will be
	if (str != NULL)
		return (0);
	j = 0;
	while (b < i)//malloc the numbers in a string i is is the end of the number
	{
		str[j] = format[b]; //format where the number is
		b++;
	}
	ft_print_zero(str, &print);
}