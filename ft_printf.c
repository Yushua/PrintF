/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/10 21:30:48 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/libft/libft.h"
#include "ft_printf.h"
/*
int		check_percentage(char str, int i, va_list ap, const char *format)
{
	format[i + 1] //next character after %

	//check for flags
	//check for characters, give the str after the flags and fill them up
	if (format == 'c')
		str = ft_printf_c(va_arg(ap, char); **
	else if (format == 's')
		str = ft_printf_s(va_arg(ap, char)); **
	else if (format == 'p')
		str = ft_printf_p(va_arg(ap, unsigned long)); **
	else if (format == 'd')
		str = ft_printf_d(va_arg(ap, int)); **
	else if (format == 'i')
		str = ft_printf_i(va_arg(ap, int)); **
	else if (format == 'u'
		str = ft_printf_u(va_arg(ap, unsigned int)); **
	else if (format == 'x'
		str = ft_printf_x(va_arg(ap, int));
	else if (format == 'X')
		str = ft_printf_X(va_arg(ap, int));
	else if (format == '%')
		str = ft_printf_per(va_arg(ap, char));
	i += 1;
	return (ft_printf(-1)); //if failed return with -1, not good, but fix later
}
*/

int		check_printf(const char *format, char str, va_list ap)
{
	int		i;
	t_print *print;
	char	*cache; //input the string that needs to be writen down after initial
	
	struct_zero(&print);
	i = 0;
	while(format[i] != '\0')
	{
		struct_zero(&print); //sets everything to 0 in struct during the loop
		if (format[i] == '%')
			{
				(*print)->begin = i; //after & for everything.
				printcache(&print, str, ap, format); //print the enxt peice if there is a %
				i = (*print)->end; //now the end, so its onverance, one furder starts anew
			}
		else (format[i] != '%')
			write(1, format[i], 1); //if not %, write it down that character.
		i++; //continue to the next character in the format
	}
	//make sure I keeps on track with the format end says where the loop must begin unless i > end
	//free everything
	if ((*print)->(*error) == 1)
		return (0); // nog fout
	return (0); //everything is printed so return 0
}

int		ft_printf(const char *format, ...) //function is bad because of end
{
	int			len;
	char		**endstr;
	char		str;
	va_list		ap;

	va_start(ap, format);
	str = (char *)malloc(sizeof(format));
	len = check_printf(format, str, ap);
	va_end(ap);
	return (len);
}

/*
**somewhere here is the loop
how do i return my trimmed string?
*/