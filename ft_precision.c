/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/22 15:18:35 by ybakker       ########   odam.nl         */
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

void		ft_precision_nb(t_print **print, va_list ap, int i, const char *format)
{
	long	nb;

	i++; //after precision
	while (format[i] >= '0')
	{
		(*print)->width_nb = -1;
		i++;
	}
	if (format[i] >= '1' || format[i] <= '9')
	{
		ft_save_nb(print, i, format); //get number into width_nb
		nb = (*print)->width_nb; //places number in nb
		(*print)->width = nb; //width after
		(*print)->flag_str_pre  = ft_find_nb_z(print);
	}
}

int			ft_save_nb(t_print **print, int i, const char *format)
{
	int		e;
	char	*nb;
	int		j;
	int		b;

	e = (*print)->end;
	b = i;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		j++;
		i++;
	}
	nb = ((char *)malloc(j * sizeof(char)));
	if (nb == NULL)
		return (0);
	j = 0;
	while (format[b] >= '0' && format[b] <= '9')
	{
		nb[j] = format[b];
		j++;
		b++;
	}
	(*print)->width_nb = ft_atoi(nb);
	free(nb);
	return (i);
}
