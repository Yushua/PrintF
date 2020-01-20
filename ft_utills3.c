/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utills3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:01:08 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 12:34:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_att_z(t_print **print, int p, int s)
{
	char	*str;
	int		i;

	i = 0;
	str = ((char *)malloc(p * sizeof(char) + 1));
	str[p] = '\0';
	while (i != p)
	{
		str[i] = '0';
		i++;
	}
	i = 0;
	p = p - s;
	while ((*print)->input_str[i] != '\0')
	{
		str[p] = (*print)->input_str[i];
		i++;
		p++;
	}
	free((*print)->input_str);
	(*print)->input_str = str;
}

char		*ft_empty_int(long w, long s, t_print **print)
{
	char	*str;
	int		i;
	int		l;

	str = (char *)malloc(sizeof(char) * (w + 1));
	if (str == NULL)
		return (NULL);
	str[w] = '\0';
	i = 0;
	while (i != w)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char		*ft_fill_z(long w, t_print **print)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * w + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (i != w)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char		ft_convergence(t_print **print, int i, const char *format)
{
	while (format[i] != '\0')
	{
		(*print)->end = i;
		if (format[i] == 'c')
			return ('c');
		else if (format[i] == 's')
			return ('s');
		else if (format[i] == '%')
			return ('%');
		else if (format[i] == 'p')
			return ('p');
		else if (format[i] == 'd')
			return ('d');
		else if (format[i] == 'i')
			return ('i');
		else if (format[i] == 'u')
			return ('u');
		else if (format[i] == 'x')
			return ('x');
		else if (format[i] == 'X')
			return ('X');
		i++;
	}
	return ('\0');
}
