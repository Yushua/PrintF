/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exemption.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 20:34:11 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 13:50:33 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strjoinn_e(char *s1, char *s2, char *str, int len1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len1] = s2[i];
		i++;
		len1++;
	}
	str[len1] = '\0';
	free(s2);
	return (str);
}

char			*ft_strjoin_e(char *s1, char *s2)
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
		ft_strjoinn_e(s1, s2, str, len1);
		return (str);
	}
	free(s1);
	free(s2);
	return (NULL);
}

char			*ft_exemption1(t_print **print, int w)
{
	int		s;

	w--;
	s = ft_strlen((*print)->input_str);
	if (w < s || w == 0)
	{
		w = s;
		w--;
	}
	(*print)->flag_str = ft_fill_z(w, print);
	while (s != 0)
	{
		(*print)->flag_str[w] = (*print)->input_str[s];
		w--;
		s--;
	}
	(*print)->flag_str = ft_strjoin_e("-", (*print)->flag_str);
	free((*print)->input_str);
	(*print)->input_str = NULL;
	return ((*print)->flag_str);
}
