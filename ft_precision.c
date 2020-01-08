/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/08 22:49:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_print **print, int i, const char *format,  va_list ap)
{
	(*print)->precision = i;
	(*print)->pre_value = (*print)->width_nb;
	ft_precision_nb(print, i, format, ap);
}

void		ft_precision_nb(t_print **print, int i, const char *format,  va_list ap)
{
	long	nb;

	i++;
	if (format[i] >= '*')
	{
		(*print)->width_nb = (va_arg(ap, int));
		if ((*print)->width_nb == 0)
			(*print)->width_nb = -1;
		(*print)->flag_str_pre = ft_empty_str(print);
	}
	else
	{
		while (format[i] >= '0')
		{
			(*print)->width_nb = -1;
			i++;
		}
		if (format[i] >= '1' || format[i] <= '9')
		{
			ft_save_nb(print, i, format);
			nb = (*print)->width_nb;
			(*print)->width = nb;
			(*print)->flag_str_pre = ft_find_nb_z(print);
		}
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
	return (i);
}
