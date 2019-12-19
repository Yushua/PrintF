/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_flag.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:27:34 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/19 22:24:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_min_zero(t_print **print, va_list ap, int i, const char *format)
{
	while (format[i] != '\0' && format[i] != '%')
	{
		while (format[i] == '0' || format[i] == '-')
		{
			if (format[i] == '-')
				(*print)->min = 1;
			else if (format[i] == '0')
				(*print)->zero = 1;
			i++;
		}
		if ((*print)->min == 1 || (*print)->zero == 1)
		{
			(*print)->position = i;
			return ;
		}
		i++;
	}
}

void		ft_find_pre(t_print **print, va_list ap, int i, const char *format)
{
	if (format[i] == '.')//check if first is .
		ft_precision(print, ap, i, format);
}

void		ft_find_flag(t_print **print, va_list ap, int i, const char *format)
{
	char	*str;

	if (format[i] == '*')
	{
		(*print)->width_nb = (va_arg(ap, int)); //get the width
		*str = ft_empty_str(print, ap, i, format);//empty str
		*(*print)->flag_str = *str;
		free(str);
		i++;
		if (format[i] == '.')
			ft_precision(print, ap, i, format);
	}
}

void		ft_find_nb(t_print **print, va_list ap, int i, const char *format)
{
	char	*str;
	long	nb;

	if (format[i] >= '1' && format[i] <= '9') //prec 1
	{
		i = ft_save_nb(print, i, format);
		if ((*print)->zero == 1) //so zero, so full with zero's
			ft_find_nb_z(print, nb);
		else // min > 0
		{
			*str = ft_empty_str(print, ap, i, format);//empty str
			*(*print)->flag_str = *str;
			free(str);
		}
		(*print)->width_nb = 0; //if used, make 0
		i++; //after number is it a precision?
		if (format[i] == '.')//check if first is .
			ft_precision(print, ap, i, format);
	}
}

void		ft_print_f(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->position = i;
	ft_min_zero(print, ap, i, format);
	i = (*print)->position;
	ft_find_pre(print, ap, i, format);//is the i a .
	ft_find_flag(print, ap, i, format);//is the i a *
	ft_find_nb(print, ap, i, format); //if its a number
	ft_save_input(print, ap, i, format);
	//function that get a number and puts it into a str
	//function finds if there is a width
	//funtion that find if there is a .
}
