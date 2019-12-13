/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:17:17 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 15:51:43 by ybakker       ########   odam.nl         */
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

int		ft_z_m(t_print **print, va_list ap, int i, const char *format)
{
	if (format[i] == '0')
	{
		(*print)->zero = 1;
		while (format[i] == '0')
			i++;
	}
	if (format[i] == '-')
	{
		(*print)->min = 1;
		while (format[i] == '-')
			i++;
	}
}

int		ft_m(t_print **print, va_list ap, int i, const char *format)
{
	if (format[i] == '-')
	{
		(*print)->min = 1;
		while (format[i] == '-')
			i++;
	}
}

void	ft_pre(t_print **print, va_list ap, int i, const char *format)
{
	while(format[i] != '\0' || i < (*print)->end)
	{
		if (format[i] == '.')
		{
			(*print)->pre = 1;
			(*print)->pre_c  = i;
			break ;			
		}
	}
}

void	ft_check(t_print **print, va_list ap, int i, const char *format)
{
	ft_pre(&print, ap, i, format);
	ft_m_z(&print, ap, i, format);// chekc is the first is a min ignores 0 and  *
	ft_z(&print, ap, i, format); 
	if (format[i] == '*')
	{
		(*print)->width_v = 1;
		(*print)->width_nb = va_arg(ap, int);
		ft_width();
	}
	else if (format[i] => '1' || format[i] =< '9')
	{
		(*print)->width_v = 1;
		ft_save_n(&print, ap, i, format);	
	} //width. no messing with -
}