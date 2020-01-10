/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_empty_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 21:50:51 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 09:55:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_empty_str(t_print **print)
{
	char	*str;
	int		nb;

	nb = (*print)->width_nb;
	str = ((char *)malloc(nb * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (nb)
	{
		nb -= 1;
		str[nb] = ' ';
	}
	return (str);
}
