/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:17:17 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 17:30:15 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_convergance(t_print **print, int i, const char *format)
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
	return (0);
}
