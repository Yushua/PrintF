/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utills.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:01:08 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 19:15:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_save_nb(t_print **print, int i, const char *format) //saves the number and puts it in width_nb
{
	int		e;
	char	*nb;
	int		j;
	int		b;

	e = (*print)->end;
	b = i;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		j++;
		i++;
	}
	nb = ((char *)malloc(j * sizeof(char)));
	if (nb == NULL)
		return (0);
	j = 0;
	while (format[b] >= '0' && format[b] <= '9')
	{
		nb[j] = format[b];
		j++;
		b++;
	}
	(*print)->width_nb = ft_atoi(nb);
	return (i);
}

char		*ft_fill_z(long nb) //malloc string with 0 in them
{
	char	*str;
	int		i;

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

char		*nwstr(void) //malloc 0 string with nul in it
{
	char	*w_fd;

	w_fd = (char *)malloc(sizeof(char));
	if (!(w_fd))
		return (0);
	w_fd[0] = '\0';
	return (w_fd);
}

char		*ft_empty_str(long nb) //malloc string filled with nothing
{
	char	*str;
	int		i;

	i = nb;
	str = ((char *)malloc(nb * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (nb)
	{
		nb -= 1;
		str[nb] = ' ';
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i += 1;
	return (i);
}
