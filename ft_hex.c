/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:30:09 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 14:58:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(long i, long j, t_print **print)
{
	long		nb;
	char		*str;

	nb = i;
	if (i <= 16)
		j++;
	else
	{
		nb = i;
		while (i != 0)
		{
			i = i / 16;
			j++;
		}
	}
	str = ((char *)malloc(j * sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = nb;
	str = ft_hex_two(str, print, j, i);
	return (str);
}

char	*ft_hex_two(char *str, t_print **print, long j, long i)
{
	long		jj;
	long		remain;

	jj = 0;
	str[jj] = '0';
	jj++;
	str[jj] = 'x';
	jj++;
	while (i > 0)
	{
		j -= 1;
		remain = i % 16;
		i = i / 16;
		jj = j + 2;
		str[jj] = ft_turn_hex(remain, print);
		jj -= 1;
	}
	return (str);
}

char	ft_turn_hex(long remain, t_print **print)
{
	char	c;
	char	con;

	con = (*print)->convergence;
	if (remain >= 0 && remain <= 9)
		c = (remain + '0');
	else if (con == 'x' || con == 'p')
		c = (remain + 'a' - 10);
	else
		c = (remain + 'A' - 10);
	return (c);
}

void	ft_print_x(t_print **print, va_list ap, int i)
{
	int		j;

	j = 0;
	i = (va_arg(ap, unsigned long));
	(*print)->input_str  = ft_hex(i, j, print);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_p(t_print **print, va_list ap)
{
	int				j;
	unsigned long	ii;
	char			*str;

	j = 0;
	ii = *(va_arg(ap, unsigned long *));
	(*print)->input_str = ft_hex(ii, j, print); //changed str to (*print)->input_str
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

/*
	int		j;
	unsigned long	ii;
	char	*str;

	j = 0;
	if (atoi((va_arg(ap, unsigned long)) != NULL)
	ii = (va_arg(ap, unsigned long) != NULL) ? (va_arg(ap, unsigned long) : 0;
	if (ii == (unsigned long) NULL)
		ii = 0;
	str  = ft_hex(ii, j, print);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
	 */