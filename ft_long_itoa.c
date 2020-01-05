/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_long_itoa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 14:18:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/05 15:31:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_len(long long nb)
{
	long long	size;

	if (nb == 0)
		return (nb + 1);
	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size += 1;
	}
	while (nb != 0)
	{
		nb /= 10;
		size += 1;
	}
	return (size);
}

static long long	ft_min(long long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_long_itoa(long long n)
{
	long long	nn;
	long long	l;
	char	*str;

	nn = n;
	l = ft_len(nn);
	if (l == 0)
		l = 1;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[l] = '\0';
	l -= 1;
	if (nn < 0)
		nn = -nn;
	while (l >= 0)
	{
		str[l] = (nn % 10) + '0';
		l -= 1;
		nn /= 10;
	}
	if (ft_min(n))
		str[0] = '-';
	return (str);
}
