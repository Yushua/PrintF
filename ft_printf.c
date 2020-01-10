/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 11:01:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_printf_check(format, ap);
	va_end(ap);
	return (len);
}

void			ft_print(t_print **print, va_list ap, int i, const char *format)
{
	i++;
	if (format[i] == '%')
	{
		write(1, &format[i], 1);
		(*print)->position = i;
		(*print)->len++;
	}
	else
	{
		(*print)->convergence = ft_convergence(print, i, format);
		if ((*print)->convergence != '\0')
		{
			ft_print_f(print, ap, i, format);
			(*print)->position = (*print)->end;
		}
	}
}

char			ft_convergence(t_print **print, int i, const char *format)
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
	return ('\0');
}

void			ft_destruct_free(t_print **print)
{
	free((*print)->flag_str);
	free((*print)->flag_str_pre);
	free((*print)->input_str);
}

int				ft_printf_check(const char *format, va_list ap)
{
	long		i;
	t_print		*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (print == NULL)
		return (0);
	struct_zero(&print);
	print->len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_print(&print, ap, i, format);
			i = print->position;
			i++;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			print->len++;
			i++;
		}
		struct_zero(&print);
	}
	ft_destruct_free(&print);
	return (print->len);
}
