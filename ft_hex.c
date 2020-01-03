/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:30:09 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/03 16:48:11 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(int i, int j, t_print **print)
{
	int		j;
	int		nb;
	char	*str;

	nb = i;
	if (i <= 16)
		j++;
	else
	{
		i = (i / 16);
		(*print)->start = nb - i;
		j++;
		while (i <= 16)
		{
			i = (i / 16);
			j++;
		}
	}
	str = ft_hex_two(str, print, j, i);
	return (str);
}

char	*ft_hex_two(char *str, t_print **print, int j, int i)
{
	str = ((char *)malloc(j * sizeof(char)));
	if (str == NULL)
		return (NULL);
	if ((*print)->convergence == 'p')
		str = ft_pointer(str, print);
	while (j != 0)
	{
		if (i <= 16)
			str[jj] = ft_turn_hex(i, print);
		j -= 1;
		i = (*print)->start;
		i = (i /= 16);
		(*print)->start = i;
		while (i >= 16)
			i = (i / 16);
	}
	return (str);
}

char	ft_turn_hex(int i, t_print **print)
{
	char	c;
	char	con;

	if (i >= 1 && i <= 9)
		c = (i + '0');
	else if (con == 'x' || con == 'p')
	{
		c = (i + 'a');
	}
	else
	{
		c = (i + 'A');
	}
	return (c);
}

char	*ft_pointer(char *str, t_print **print)
{
	int		i;
	char	con;

	con = (*print)->convergence;
	i = 0;
	if (con == 'p')
	{
		str[i] = '0';
		i++;
		str[i] = 'x';
	}
	return (str);
}
