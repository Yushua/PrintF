/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 15:52:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_check(const char *format, va_list ap)
{
	int			i;
	t_print		*print;

	print = (t_print*)malloc(sizeof(t_print));
	struct_zero(&print);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_printcache(&print, ap, i, format);
			i = (*print)->end;
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
		struct_zero(&print);
		i++;
	}
	//free everything
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	char		**endstr;
	char		str;
	va_list		ap;

	va_start(ap, format);
	ft_rintf_check(format, ap);
	va_end(ap);
	return (0);
}

/*
print->begin = i;
/i++;
ft_end(&print, ap, format);
if (print->convergions != '%')
{
	//printcache(&print, ap, i, format);
	i = print->end;
}
*/