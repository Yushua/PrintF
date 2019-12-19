/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:27:40 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/19 19:30:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string_1(t_print **print)
{
	char	*str;
	long	i;
	int		len; //lenght to return at the end of printf

	i = 0;
	len = (*print)->len;
	*str = (*print)->input_str;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	(*print)->len = len;
}

//flag_str;
//input_str;
//width_nb; is bigger or smaller

void		ft_print(t_print **print, va_list ap, int i, const char *format)
{
	i++; //next character after the first %
	(*print)->convergance = ft_convergance(print, i, format); //get the ending
	if ((*print)->convergance == '%')
	{
		write(1, &format[i], 1);
		(*print)->position = i;
	}
	else if ((*print)->convergance != '\0')
	{
		ft_print_f(print, ap, i, format); //in flag_str
		(*print)->position = (*print)->end;
	}
}
