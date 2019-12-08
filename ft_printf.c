/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:47:11 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:41:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	cleanap(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}

int		check_percentage(char str, int i, va_list ap, const char *format)
{
	format[i + 1] //next character after %

	//check for flags
	//check for characters, give the str after the flags and fill them up
	if (format == 'c')
		str = ft_printf_c(va_arg(ap, char); **
	else if (format == 's')
		str = ft_printf_s(va_arg(ap, char)); **
	else if (format == 'p')
		str = ft_printf_p(va_arg(ap, unsigned long)); **
	else if (format == 'd')
		str = ft_printf_d(va_arg(ap, int)); **
	else if (format == 'i')
		str = ft_printf_i(va_arg(ap, int)); **
	else if (format == 'u'
		str = ft_printf_u(va_arg(ap, unsigned int)); **
	else if (format == 'x'
		str = ft_printf_x(va_arg(ap, int));
	else if (format == 'X')
		str = ft_printf_X(va_arg(ap, int));
	else if (format == '%')
		str = ft_printf_per(va_arg(ap, char));
	i += 1;
	return (ft_printf(-1)); //if failed return with -1, not good, but fix later
}

int		check_printf(const char *format, char str, va_list ap)
{
	int		i;

	while(format[i] != '\0')
	{
		if (format == '%')
			return (check_percentage(str, i, ap, format));
		else
			i += 1;
	}
	return (0); //fix later
}

int		ft_printf(const char *format, ...)
{
	int			len;
	char		str;
	va_list		ap;

	va_start(ap, format);
	str = (char *)malloc(sizeof(format));
	len = check_printf(format, str, ap);
	va_end(ap);
	return (len);
}
