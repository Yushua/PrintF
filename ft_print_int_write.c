/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/12 00:42:45 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_int(t_print **print)
{
	int		s;
	int 	p;

	s = ft_strlen((*print)->input_str);
	p = (*print)->p_width;
	if ((*print)->neg == 1 && s != 0)
		s--;
	if (s == 0)
		(*print)->input_str = NULL;
	if ((*print)->min == 1)
		(*print)->input_str = ft_int_min(s, print);
	else if ((*print)->min != 1)
		(*print)->input_str = ft_int_no(s, print, p);
}

char		*ft_int_no(long s, t_print **print, long p)
{
	int		w; //lengt of width
	int		i;

	i = 0;
	w = (*print)->w_width;
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
	if ((*print)->neg == 1)
		((*print)->flag_str) = ft_strjoin("-", (*print)->flag_str);
	return ((*print)->flag_str);
}

char		*ft_int_min(long s, t_print **print)
{
	int		w;
	int		i;

	i = 0;
	w = (*print)->w_width;
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
