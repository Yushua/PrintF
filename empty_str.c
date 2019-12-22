/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 15:19:26 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/22 16:20:20 by ybakker       ########   odam.nl         */
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
