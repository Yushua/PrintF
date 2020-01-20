/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 13:59:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_find_pre(t_print **print, int i, const char *format,
							va_list ap)
{
	while (format[i] != '.' && format[i] != (*print)->convergence)
		i++;
	if (format[i] == '.')
	{
		(*print)->pre = 1;
		ft_precision_nb(print, i, format, ap);
	}
}

static void		ft_precision_nbb(t_print **print, int i, const char *format,
									va_list ap)
{
	if (format[i] == '0')
	{
		while (format[i] == '0' && format[i] != '%')
		{
			(*print)->width_nb = 0;
			(*print)->error = -1;
			i++;
		}
	}
	else if (format[i] != '0')
	{
		(*print)->width_nb = -1;
		(*print)->error = 0;
	}
	else if (format[i] >= '1' || format[i] <= '9')
	{
		ft_save_nb(print, i, format);
		(*print)->p_width = (*print)->width_nb;
		(*print)->width_nb = 0;
		(*print)->error = 0;
	}
}

void			ft_precision_nb(t_print **print, int i, const char *format,
							va_list ap)
{
	i++;
	if (format[i] == (*print)->convergence)
		(*print)->error = -1;
	else if (format[i] == '*')
	{
		(*print)->p_width = (va_arg(ap, int));
		(*print)->pre = (*print)->p_width;
	}
	else if (format[i] >= '1' || format[i] <= '9')
	{
		ft_save_nb(print, i, format);
		(*print)->error = 0;
		(*print)->p_width = (*print)->width_nb;
	}
	else if (format[i] == '0')
		ft_precision_nbb(print, i, format, ap);
	else
		(*print)->error = -1;
}
