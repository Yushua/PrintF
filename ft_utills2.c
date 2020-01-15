/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utills2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:01:08 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 22:28:56 by ybakker       ########   odam.nl         */
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
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

void		ft_take_min(t_print **print)
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

char		*a_to_a(t_print **print)
{
	char	*str;
	int		i;

	str = (*print)->input_str;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A';
		i++;
	}
	return (str);
}
