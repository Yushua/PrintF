/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/12 01:22:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_int(t_print **print)
{
	int		s;
	int 	p;
	int		w;

	w = (*print)->w_width;
	if ((*print)->neg < 0)
	{
		w++;
		ft_take_min(print);
	}
	s = ft_strlen((*print)->input_str);
	p = (*print)->p_width;
	if (p < s)
		p = s;
	if (s == 0)
		(*print)->input_str = NULL;
	if ((*print)->min == 1)
		(*print)->input_str = ft_int_min(s, w, print);
	else if ((*print)->min != 1)
		(*print)->input_str = ft_int_no(s, w, print, p);
}

char		*ft_int_no(long s, int w, t_print **print, long p)
{
	int		i;

	i = 0;
	if (w == 0)
		w = s;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w, s, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	if (p > 0)
		ft_fill_z_int(print, w, p);
	w = w - s;
	while (i != s)
	{
		(*print)->flag_str[w] = (*print)->input_str[i];
		i++;
		w++;
	}
	if ((*print)->neg < 0 && p == 0)
		((*print)->flag_str) = ft_strjoin("-", (*print)->flag_str);
	else if ((*print)->neg < 0 && p > 0)
	{
		p = 10;
		(*print)->flag_str[p] = '-';
	}
	return ((*print)->flag_str);
}

char		*ft_int_min(long s, int w, t_print **print)
{
	int		i;

	i = 0;
	while (i != s && (*print)->input_str[i] != '\0' &&
			(*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[i] = (*print)->input_str[i];
		i++;
	}
	return ((*print)->flag_str);
}

void	ft_fill_z_int(t_print **print, int w, long p) //w is location
{
	char	*str;

	str = (*print)->flag_str;
	w--;
	while (p != 0)
	{
		str[w] = '0';
		p--;
		w--;
	}
}

char		*ft_empty_int(long nb, long s, t_print **print)
{
	char	*str;
	int		i;
	int		l;

	i = nb;
	nb++;
	str = ((char *)malloc(nb * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (nb)
	{
		nb -= 1;
		str[nb] = ' ';
	}
	str[i] = '\0';
	return (str);
}

char		*ft_fill_z(long nb, long s, t_print **print)
{
	char	*str;
	int		i;

	str = ((char *)malloc(nb * sizeof(char)));
	if ((*print)->neg == 1)
		nb--;
	if (str == NULL)
		return (NULL);
	while (nb)
	{
		nb -= 1;
		str[nb] = '0';
	}
	return (str);
}

//min is taken away, make sure that the - is placed maybe combine the two, or something else simpler
//negative stil has some issues, work on that