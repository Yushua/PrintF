/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:27:34 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 12:54:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_min_zero(t_print **print, va_list ap, int i, const char *format)
{
	while (format[i] != '\0' || format[i] != '%')
	{
		while (format[i] == '0' || format[i] == '-')
		{
			if (format[i] == '-')
			{
				(*print)->min = 1;
				(*print)->position = i;
			}
			else if (format[i] == '0')
			{
				(*print)->zero = 1;
				(*print)->position = i;
			}
			i++;
		}
		i++;
	}
}

void		ft_find_pre(t_print **print, va_list ap, int i, const char *format)
{
	while (format[i] != '\0' || format[i] != '%')
	{
		if (format[i] == '.')
		{
			(*print)->pre = 1;
			(*print)->pre_c = i;
			break ;
		}
		i++;
	}
}

void		ft_print_f(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->position = i;
	ft_min_zero(print, ap, i, format);
	ft_find_pre(print, ap, i, format);
	//function that get a number and puts it into a str
	//function finds if there is a width
	//funtion that find if there is a .

}
