/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 15:19:26 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/15 16:17:02 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char		ft_empty_str(t_pritnt **prin, va_list ap, int i, const char *format)
{
	char	str;
	int		y;

	y = 0;
	y = (*print)->width_nb;
	str = ((char *)malloc(sizeof(char) * ((*print)->width_nb + 1)));
	if (str == NULL)
		return ;
	(*print)->width_nb = 0;
	while (y != 0)
	{
		str[y] = ' ';
		y--;
	}
	return (str);
}
