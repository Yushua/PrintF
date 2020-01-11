/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_width.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:27:34 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 18:04:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_f(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->position = i;
	if (format[i] == '0' || format[i] == '-')
	{
		ft_min_zero(print, i, format);
	}
	if ((*print)->min == 1)
		(*print)->zero = 0;
	i = (*print)->position;
	ft_find_pre(print, i, format, ap);
	ft_find_flag(print, ap, i, format);
	ft_find_nb(print, i, format, ap);
	ft_save_input(print, ap, i);
}

void		ft_min_zero(t_print **print, int i, const char *format)
{
	while (format[i] != '\0' && format[i] != '%')
	{
		while (format[i] == '0' || format[i] == '-')
		{
			if (format[i] == '-')
			{
				(*print)->min = 1;
				(*print)->zero = 0;
			}
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

void		ft_find_pre(t_print **print, int i, const char *format, va_list ap)
{
	if (format[i] == '.')
		ft_precision(print, i, format, ap);
}

void		ft_find_flag(t_print **print, va_list ap, int i, const char *format)
{
	if (format[i] == '*')
	{
		(*print)->positive = 1;
		(*print)->width_nb = (va_arg(ap, int));
		if ((*print)->width_nb <= 0)
		{
			(*print)->min = 1;
			(*print)->width_nb *= -1;
		}
		(*print)->w_width = (*print)->width_nb;
		(*print)->width_nb = 0;
		i++;
		if (format[i] == '.')
			ft_precision(print, i, format, ap);
	}
}

void		ft_find_nb(t_print **print, int i, const char *format, va_list ap)
{
	if (format[i] >= '1' && format[i] <= '9')
	{
		(*print)->positive = 1;
		i = ft_save_nb(print, i, format);
		(*print)->w_width = (*print)->width_nb;
		(*print)->width_nb = 0;
		i++;
		if (format[i] == '.')
			ft_precision(print, i, format, ap);
	}
}
