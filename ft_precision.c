/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_precision.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 14:05:35 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 14:39:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void		ft_precision(t_print **print, va_list ap, int i, const char *format)
{
	long int		nb;
	char			*str;

	(*print)->pre = 1;
	(*print)->pre_c = i;
	i++;
	if (format[i] >= '1' || format[i] <= '9')
	{
		ft_save_nb(print, ap, i, format); //get number into width_nb
		nb == (*print)->width_nb; //places number in nb
		(*print)->width_nb = 0; //empties width
		str = ((char *)malloc(sizeof(char) * (nb + 1)));
		if (s != NULL)
			return ; //defence
		(*print)->flag_str = ft_bzero(str, nb);
		(*print)->position = i;
	}
}
