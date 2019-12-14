/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 12:12:08 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_check(const char *format, va_list ap)
{
	int			i;
	t_print		*print;

	print = (t_print*)malloc(sizeof(t_print));
	if (print == NULL)
		return (NULL);
	struct_zero(&print);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_print(&print, ap, i, format);
			i = print->end;
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
	ft_printf_check(format, ap);
	va_end(ap);
	return (0);
}
