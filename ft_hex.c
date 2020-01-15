/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:30:09 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 16:40:46 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LOWER_HEX "0123456789abcdef"

char	*ft_hex(unsigned long i, unsigned long j, t_print **print)
{
	unsigned long	nb;
	char			*str;

	nb = i;
	if (i <= 16)
		j++;
	else
	{
		nb = i;
		while (i > 0)
		{
			i = i / 16;
			j++;
		}
	}
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	i = nb;
	str = ft_hex_two(str, print, j, i);
	return (str);
}

char	*ft_hex_two(char *str, t_print **print, unsigned long j, unsigned long i)
{
	unsigned long		jj;
	unsigned long		remain;

	jj = 0;
	if ((*print)->convergence == 'p')
	{
		str[jj] = '0';
		jj++;
		str[jj] = 'x';
		jj++;
		j += 2;
	}
	j--;
	if (i <= 16)
		str[j] = LOWER_HEX[i];
	else
	{
		while (i != 0)
		{
			remain = i % 16;
			i = i / 16;
			str[j] = LOWER_HEX[remain];
			j--;
		}
	}
	return (str);
}

void	ft_print_x(t_print **print, va_list ap)
{
	unsigned long	j;
	unsigned long	i;

	j = 0;
	i = (va_arg(ap, unsigned long));
	(*print)->input_str  = ft_hex(i, j, print);
	ft_write_hex(print);
	if ((*print)->convergence == 'X' && (*print)->input_str != NULL)
	{
		i = 'x' - 'X';
		while ((*print)->input_str[j] != '\0')
		{
			if ((*print)->input_str[j] >= 'a' && (*print)->input_str[j] <= 'z')
				(*print)->input_str[j] = (*print)->input_str[j] - i;
			j++;
		}
	}
	ft_write_string_1(print);
}

void	ft_print_p(t_print **print, va_list ap)
{
	unsigned long	j;
	unsigned long	ii;
	char			*str;

	j = 0;
	ii = va_arg(ap, unsigned long);
	(*print)->ii = ii;
	(*print)->input_str = ft_hex(ii, j, print); //changed str to (*print)->input_str
	ft_write_p(print);
	ft_write_string_1(print);
}
