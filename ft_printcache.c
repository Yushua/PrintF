/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printcache.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:41:08 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 17:05:40 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char	ft_convergance(const char (*format), t_print **print, int i)
{
	while (format[i] != '\0')
	{
		(*print)->end = i;
		if (format[i] == 'c')
			return ('c');
		else if (format[i] == 's')
			return ('s');
		else if (format[i] == 'p')
			return ('p');
		else if (format[i] == 'd')
			return ('d');
		else if (format[i] == 'i')
			return ('i');
		else if (format[i] == 'u')
			return ('u');
		else if (format[i] == 'x')
			return ('x');
		else if (format[i] == 'X')
			return ('X');
		else if (format[i] == '%')
			return ('%');
		i++;
	}
	return (formation->error);
}

/*
**check what the convergence is for va_arg
*/

/*
**first make the flags
**then use va_arg to make the input
**then combine the elnght using struct (could be a function on itself)
**then write the outcome using ft_putstr_fd
*/
t_print		printcache(t_print **print, char str, va_list ap, const char *format)
{
	char    *cache;
	char	str_flag;
	char	str_con;
	
	i++; //next character after %
	(*print)->convergions = ft_convergance(*format, &print, i);//remmebers the FIRST convergance, now have end
	ft_i_or_c();
	if (format[i] == '.' || format[i] == '-' || format[i] == '*' ||
		format[i] => '0' || format =< '9');
		ft_flag_check(&print, format, i, ap);
	ft_convergance_check();//check convergions with va_arg, then combine what you got and make the string and print out in ft_putchar
	ft_checkwidth(str_flag, str_con); //check with for what to do with the flags, multiple options, make sure it works.
	ft_writepiece(str_flag, str_con);	//ft_putstr_fd(cache, 1); write it down using the construct given
	return (0);
}

/*
**after you found the % you add 1 to the position. the make sure all 
**the structs are 0 in the beginding and that begin is begin + i so when you come bakc here you start with
**the next %
***/
