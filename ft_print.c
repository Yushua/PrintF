/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:27:40 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 12:07:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print(t_print **print, va_list ap, int i, const char *format)
{
	i++; //next character after the frist %
	i = (*print)->begin;
	(*print)->convergance = ft_convergance(print, i, format); //get the ending
	if ((*print)->convergance == '%')
	{
		write(1, &format[i], 1);
		return ;
	}
	ft_print_f(print, ap, i, format);
	//ft_print_str(&print, ap, i, format);
}

