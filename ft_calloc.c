/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:14:32 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/16 22:06:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nitems == 0 || size == 0)
		return (NULL);
	result = malloc(size * nitems);
	if (result == NULL)
		return (NULL);
	while (i <= nitems)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}
