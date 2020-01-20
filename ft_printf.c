/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 12:33:41 by ybakker       ########   odam.nl         */
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
	if (format[i] == ' ')
	{
		while (format[i] == ' ')
		{
			i++;
		}
	}
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

static	void	ft_printf_checkk(const char *format, va_list ap, t_print *print)
{
	long				i;

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
}

void			ft_destruct_free(t_print *print)
{
	free(print->flag_str);
	free(print->input_str);
	free(print);
}

int				ft_printf_check(const char *format, va_list ap)
{
	t_print				*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (print == NULL)
		return (0);
	struct_zero(&print);
	print->len = 0;
	ft_printf_checkk(format, ap, print);
	ft_destruct_free(print);
	return (print->len);
}
