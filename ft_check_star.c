/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_star.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 16:42:39 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 15:58:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**star va_arg(ap, int); stop with the enxt steps
**numbers stop with star
**zero 
*/

t_print		ft_c_s_star(t_print **print, const char *format, int  i, va_list ap)
{
	char	str;
	i = va_arg(va_arg(ap,int)); //character says how long the space in empty spaces
	str = ((char *)malloc(sizeof(char) * (i));
	if (str != NULL)
		return (0);
	while (i > 0)
	{
		str[i] = " ";
		i =- 1;
	}
	(*print)->flags = str;
	free(str);
}

t_print	ft_print_number(char str) //str has the number of spaces you need to have empty
{
	int		i;

	i = atoi(str);
	free(str);
	str = ((char *)malloc(sizeof(char) * (i + 1));
	str = ft_memset(str, " ", i);	//use memset for the heoveelheid spaces
	(*print)->flags = str;
	free(str);
}

t_print		ft_c_s_nummer(t_print **print, const char *format, int  i, va_list ap) //i is the number where it starts
{
	char	str;
	int		j;
	int		b;
	
	b = i; //b is the beginning
	j = 0;
	while (format[i] => 0 || format[i] =< 9) //get the numbers out of format of how long
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
	ft_print_number(str, &print);
}

int   ft_check_star(t_print **print, const char *format, int  i, va_list ap);
{ 
	char	str;
	while((format[i] != '\0') || i != (*print)->end) //check for * end is the stop else it goes furder than the %
	{
		if (format[i] == '*')
		{
			ft_c_s_star(&print, format, i, ap); 
			return (1)          
		}
		else if (format[i] => '1' || format[i] =< '9')
		{
			ft_c_s_nummer((&print, format, i, ap));
			return (1);
		}
		else if (format[i] => '0')
		{
			(*print)->zer0 == 1; //so if a converance is there, it nullifies 0 if used later accidently
			ft_check_zero(&print, format, i, ap);// i is now when its 0 first
			return (1);        
		}
	}
}
