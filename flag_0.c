/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_0.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 15:55:21 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 18:36:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print     flag_0(t_print **print, const char (*format), int i)
{
	int		y;

	y = i;
	i++;
	while (i != (*print)->end || format[i] => '1' || format[i] =< '9')
	{
		if (format[i] == '+')
			(*print)->positive = 1;
		if (format[i] == '-')
		{
			(*print)->negative = 1;
			flag_min(&print, format, i);
		}
		if (((*print)->positive == 1) && ((*print)->negative == 1);
			flag_plus(&print, format, i);
		i++;
	}
	(*print)->widthf = str_zero(&print, format, y)
	y = (*print)->widthf;
	(*print)->flags = ft_bzero(y);
	return (0);
}
/*
**check if any ov the flag overrides are stil there for 0, if not,
**continue with 0, if is, cotineu to that flags function
** cna ignore 0, but if it higher than 0, the the fucntion stops.
** if its plus, make sure positive is plus , so you can add that to the lenght because it needs a plus
** if min and plus, move to min where i'll make a function that does this ebcause 0
**is not needed anymore
*/

t_print		str_zero(t_print **print, const char (*format), int y)
{
	int		i
	int		e;
	char	nb;

	i = 0;
	while (y != (*print)->end || format[y] =< '1' || format[iy] => '9')
	{
		if (format[y] => '1' || format[y] =< '9')
			nb[i] = format[y]
			i++;
		y++;
	}
	if (nb[0] == '\0')
		return (0);
	return (ft_itoa(nb));

}

/*
** e - b = widthf
** i don't have to do - but I could?
*/