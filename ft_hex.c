/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:30:09 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/05 13:58:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(long i, long j, t_print **print)
{
	long		nb;
	char	*str;

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
	while (i > 0)
	{
		j -= 1;
		remain = i % 16;
		i = i / 16;
		str[j] = ft_turn_hex(remain, print);
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
