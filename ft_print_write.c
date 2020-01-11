/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_write.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 18:30:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_string_1(t_print **print)
{
	char	*str;
	long	i;

	i = 0;
	str = (*print)->input_str;
	while (str != NULL && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		(*print)->len++;
	}
}

void		ft_write_str(t_print **print)
{
	int		s;
	int 	p;

	s = ft_strlen((*print)->input_str);
	p = (*print)->p_width;
	if (s == 0 || (*print)->error == -1)
		(*print)->input_str = NULL;
	else if (s > p && p != -1)
		s = p;
	if ((*print)->min == 1)
		(*print)->input_str = ft_str_min(s, print);
	else if ((*print)->min != 1)
		(*print)->input_str = ft_str_no(s, print);
}

char		*ft_str_min(long s, t_print **print)
{
	int		w;
	int		i;

	w = (*print)->w_width;
	(*print)->flag_str = ft_empty_str(w);
	if (w < s)
		return ((*print)->input_str);
	else if ((*print)->error == -1)
		return ((*print)->flag_str);
	while ((*print)->input_str[i] != '\0' &&
			(*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[i] = (*print)->input_str[i];
		i++;
	}
	return ((*print)->flag_str);
}

char		*ft_str_no(long s, t_print **print)
{
	int		w;
	int		i;

	i = 0;
	if (w == 0 && s > 0)
		w = s;
	w = (*print)->w_width;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w);
	else
	{
		(*print)->flag_str = ft_empty_str(w);;
	}
	if (w < s)
		return ((*print)->input_str);
	else if ((*print)->error == -1)
		return ((*print)->flag_str);
	w = w - s;
	while (i != s && (*print)->input_str[i] != '\0' &&
			(*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[w] = (*print)->input_str[i];
		i++;
		w++;
	}
	return ((*print)->flag_str);
}

void		ft_write_pro(t_print **print)
{
	int		w;
	int		i;

	i = 0;
	w = (*print)->w_width;
	if ((*print)->min == 1)
	{
		(*print)->input_str = ft_empty_str(w);
		(*print)->input_str[i] = '%';
	}
	else
	{
		w--;
		if ((*print)->zero == 1)
			(*print)->input_str = ft_fill_z(w);
		else
			(*print)->input_str = ft_empty_str(w);
		(*print)->input_str[w] = '%';
	}
}
