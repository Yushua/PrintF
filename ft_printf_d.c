/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_d.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:31:56 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 14:52:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_len(long nb)
{
	size_t	size;

	if (nb == 0)
		return (nb + 1);
	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size += 1;
	}
	while (nb != 0)
	{
		nb /= 10;
		size += 1;
	}
	return (size);
}

static int	ft_min(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n) //right to left
{
	long	nn;
	long	l;
	char	*str;

	nn = n;
	l = ft_len(nn);
	if (l == 0)
		l = 1;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[l] = '\0';
	l -= 1;
	if (nn < 0)
		nn = -nn;
	while (l >= 0)
	{
		str[l] = (nn % 10) + '0';
		l -= 1;
		nn /= 10;
	}
	if (ft_min(n))
		str[0] = '-';
	return (str);
}

ft_printf_d(int i)
{
    char    str;

    str = ft_itoa(i);
    return (str);
}