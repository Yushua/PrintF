/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:32:07 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:52:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_printf_str(char const *s)
{
	int		i;
	char	c;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		c = (char)s[i];
		ft_putchar(c);
		i += 1;
	}
}

//write whole string unless its a % character
//so you get the ap, but is the " " included? if so, 
//make sure they're there and then print the inbetween