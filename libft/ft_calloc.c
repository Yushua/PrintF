/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:14:32 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 13:42:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = malloc(sizeof(char) * (count * size));
	if (str == 0)
		return (0);
	while (i < (count * size))
	{
		str[i] = 0;
		i += 1;
	}
	return ((void*)str);
}
