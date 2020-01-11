/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utills2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:01:08 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 23:57:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_string_1(t_print **print)
{
	char	*str;
	long	i;

	i = 0;
	str = (*print)->input_str;
	while (str != NULL && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		(*print)->len++;
	}
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	count;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	count = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join += 1;
		s1 += 1;
		count += 1;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join += 1;
		s2 += 1;
		count += 1;
	}
	*join = '\0';
	return (join - count);
}

void	ft_take_min(t_print **print)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while ((*print)->input_str[j] != '\0')
	{
		(*print)->input_str[i] = (*print)->input_str[j];
		i++;
		j++;
	}
	(*print)->input_str[i] = '\0';
}
