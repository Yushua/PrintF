/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 16:30:59 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 16:31:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(char *s1)
{
	char	*s;

	s = ((char *)malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (s != NULL)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}

size_t		ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
