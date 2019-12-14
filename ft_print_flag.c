/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:27:34 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 15:01:55 by ybakker       ########   odam.nl         */
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
	if (format[i] == '.')//check if first is .
	{
		ft_precision(print, ap, i, format);
	}
}

void		ft_find_width(t_print **print, va_list ap, int i, const char *format)
{
	if (format[i] == '*')
	{
		(*print)->width_nb = (va_arg(ap, int));
		(*print)->pre_c = i;
		//make * str saving in flag_str;
		i++
		if (format[i] == '.')
			ft_precision(print, ap, i, format);
	}
	else if (format[i] >= '1' || format[i] <= '9') //prec 1
	{
		ft_save_nb(print, ap, i, format);
		if ((*print)->zero != 0)
		{
			//str with bzero in flag_str;
			ft_precision(print, ap, i, format);
		}
		else
		{
			//calloc in flag_str;
		}
	}
}

void		ft_print_f(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->position = i;
	ft_min_zero(print, ap, i, format);
	i = (*print)->position; // after min and zero
	ft_find_width(print, ap, i, format);//is the i a
	i = (*print)->position;
	ft_find_pre(print, ap, i, format);//is the i a .
	ft_flag_str(print, ap, i, format);
	//function that get a number and puts it into a str
	//function finds if there is a width
	//funtion that find if there is a .

}
