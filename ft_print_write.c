/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_write.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/05 11:53:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_string_1(t_print **print)
{
	char	*str;
	long	i;
	int		len; //lenght to return at the end of printf

	i = 0;
	len = (*print)->len;
	str = (*print)->input_str;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	(*print)->len = len + (*print)->len;
}

void		ft_write_str(t_print **print)
{
	char	*str;
	char	*str_f;
	long	s; //len str
	long	f; //len str_f
	long	width; //width to print

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	s = ft_strlen(str); //first, place where it begins
	f = ft_strlen(str_f); //second
	width = (*print)->width_nb;
	if ((*print)->width_nb < -1)
		(*print)->width_nb = -1;
	if ((*print)->width_nb == -1)
		(*print)->input_str = (*print)->flag_str; //because the precsion is smaller, it means nothing should be printed
	else if (s >= f)
	{
		if ((*print)->min == 1)
			(*print)->input_str = ft_str_min(s, print, width);
		else if ((*print)->min != 1)
			(*print)->input_str = ft_str_no(s, f, print, width);
	}
	else if (f > s)
		(*print)->input_str = str_f;//now pointer flag string is it.
}

char		*ft_str_min(long s, t_print **print, long width)
{
	char	*str;
	char	*str_f;
	long	i;

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	i = 0;
	while (i != width)
	{
		str[i] = str_f[i];
		i++;
	}
	return (str);
}

char		*ft_str_no(long s, long f, t_print **print, long width)
{
	char	*str;
	char	*str_f;

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	while (s != 0 && str_f != '\0')
	{
		str[f] = str_f[width];
		f -= 1;
		width -= 1;
		s -= 1;
	}
	return (str);
}
