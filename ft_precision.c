/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/16 17:47:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_print **print, va_list ap, int i, const char *format)
{
	long int		nb;
	char			*str;

	(*print)->precision = i;
	(*print)->pre_value = (*print)->width_nb;
	ft_precision_nb(print, ap, i, format); //the str after .
}

void	ft_precision_nb(t_print **print, va_list ap, int i, const char *format)
{
	i++; //after precision
	if (format[i] >= '1' || format[i] <= '9')
	{
		ft_save_nb(print, ap, i, format); //get number into width_nb
		nb == (*print)->width_nb; //places number in nb
		(*print)->width_nb = 0; //empties width
		str = ((char *)malloc(sizeof(char) * (nb + 1)));
		if (s != NULL)
			return ; //defence
		(*print)->flag_str_pre = ft_bzero(str, nb);
		(*print)->position = i; //do you need it, because this is the end?
	}
}
