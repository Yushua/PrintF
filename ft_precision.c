/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 14:54:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_print **print, int i, const char *format,  va_list ap)
{
	ft_precision_nb(print, i, format, ap);
}

void		ft_precision_nb(t_print **print, int i, const char *format,  va_list ap)
{
	long	nb;

	i++;
	if (format[i] == '*')
	{
		(*print)->p_width = (va_arg(ap, int));
		(*print)->width_nb = (*print)->p_width;
		(*print)->flag_str_pre = ft_empty_str(print);
	}
	else
	{
		while (format[i] == '0')
		{
			(*print)->width_nb = -1;
			(*print)->error = -1;
			i++;
		}
		if (format[i] >= '1' || format[i] <= '9')
		{
			ft_save_nb(print, i, format);
			(*print)->error = 0;
			(*print)->p_width = (*print)->width_nb;
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
