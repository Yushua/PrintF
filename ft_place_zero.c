/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_place_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:29:29 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/22 16:19:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_find_nb_z(t_print **print)
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
		str[nb] = '0';
	}
	return (str);
}
